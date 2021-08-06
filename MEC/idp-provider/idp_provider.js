var port = 15005;

var express = require("express");

const axios = require("axios");

var app = express();
var cors = require("cors");
var SData = require("simple-data-storage");
var jsonParser = require("body-parser").json({ limit: "50mb" });

require("custom-env").env(true);

app.use(cors());
app.options("*", cors());

var jsrsasign = require("jsrsasign");
var rsaKey = jsrsasign.KEYUTIL.generateKeypair("RSA", 1024);
var e = jsrsasign.hextob64u(rsaKey.pubKeyObj.e.toString(16));
var n = jsrsasign.hextob64u(rsaKey.pubKeyObj.n.toString(16));

var path = "/oidc";
var metadataPath = path + "/.well-known/openid-configuration";
var signingKeysPath = path + "/.well-known/jwks";
var authorizationPath = path + "/connect/authorize";
var userInfoPath = path + "/connect/userinfo";
var endSessionPath = path + "/connect/endsession";
var userDataStorePath = path + "/store";
var userDataPath = "/user/data";
var validateAccessTokenPath = path + "/validateAccessToken";

var metadata = {
  issuer: path,
  jwks_uri: signingKeysPath,
  authorization_endpoint: authorizationPath,
  userinfo_endpoint: userInfoPath,
  end_session_endpoint: endSessionPath,
};

const mecManagerUrl = process.env.MEC_MANAGER_URL;

function prependBaseUrlToMetadata(baseUrl) {
  for (var name in metadata) {
    metadata[name] = baseUrl + metadata[name];
  }
}

var keys = {
  keys: [
    {
      kty: "RSA",
      use: "sig",
      kid: "1",
      e: e,
      n: n,
    },
  ],
};

var claims = {
  sub: "818727",
  email: "AliceSmith@email.com",
  email_verified: true,
  role: ["Admin", "Geek"],
};

function genAccessToken() {
  return parseInt(Math.random().toString().replace("0.", "")).toString(16);
}

function hashAccessToken(access_token) {
  var hash = jsrsasign.crypto.Util.hashString(access_token, "sha256");
  var left = hash.substr(0, hash.length / 2);
  var left_b64u = jsrsasign.hextob64u(left);
  return left_b64u;
}

const getSubscriptionData = (remote_ip) => {
  if (!SData.has(remote_ip)) return Promise.resolve(null);

  if ("subscriptionData" in SData(remote_ip))
    return Promise.resolve(SData(remote_ip).subscriptionData);

  const st = new Date().getTime();
  console.log("Fetching subs. data. Start at", st);
  return axios
    .get(`${mecManagerUrl}/manager/user/data/`, {
      params: {
        imsi: SData(remote_ip).imsi,
      },
    })
    .then((userDataRes) => {
      console.log(
        "User data received from MEC manager. Received at",
        new Date().getTime()
      );
      let remoteIpData = SData(remote_ip);
      remoteIpData.subscriptionData = userDataRes.data.mainData;
      SData(remote_ip, remoteIpData);
      return userDataRes.data.mainData;
    });
};

function genIdToken(remote_ip, aud, nonce, access_token) {
  var now = parseInt(Date.now() / 1000);
  var payload = null;

  // If subscription data for this user is not present, then fetch during authentication

  return getSubscriptionData(remote_ip)
    .then((data) => {
      console.log("Subscription data");
      console.log(data);

      payload = {
        aud: aud,
        iss: metadata.issuer,
        nonce: nonce,
        sid: "37889234079034890",
        nbf: now,
        iat: now,
        exp: now + 36000,
        idp: "some_idp",
        amr: ["password"],
      };

      console.log(remote_ip);

      if (access_token) {
        payload.at_hash = hashAccessToken(access_token);
        if (SData.has(remote_ip)) {
          console.log("sending ", SData(remote_ip).imsi);
          payload.sub = SData(remote_ip).imsi;
        } else {
          console.log("no data");
          payload.sub = claims.sub;
        }
      } else {
        for (var key in claims) {
          payload[key] = claims[key];
        }
        if (SData.has(remote_ip)) {
          console.log("sending ", SData(remote_ip).imsi);
          payload.sub = SData(remote_ip).imsi;
        } else {
          console.log("no data");
          payload.sub = claims.sub;
        }
      }

      console.log(payload);

      return jsrsasign.jws.JWS.sign(
        null,
        { alg: "RS256", kid: "1" },
        payload,
        rsaKey.prvKeyObj
      );
    })
    .catch((err) => {
      console.log("Error in Axios call");
      console.log(error);
    });
}

function isOidc(response_type) {
  var result = response_type.split(/\s+/g).filter(function (item) {
    return item === "id_token";
  });
  return !!result[0];
}

function isOAuth(response_type) {
  var result = response_type.split(/\s+/g).filter(function (item) {
    return item === "token";
  });
  return !!result[0];
}

function addFragment(url, name, value) {
  if (url.indexOf("#") < 0) {
    url += "#";
  }

  if (url[url.length - 1] !== "#") {
    url += "&";
  }

  url += encodeURIComponent(name);
  url += "=";
  url += encodeURIComponent(value);

  return url;
}

app.get(metadataPath, function (req, res, next) {
  res.json(metadata);
});

app.get(signingKeysPath, function (req, res, next) {
  res.json(keys);
});

app.get(authorizationPath, function (req, res, next) {
  var response_type = req.query.response_type;

  var url = req.query.redirect_uri;

  var state = req.query.state;
  if (state) {
    url = addFragment(url, "state", state);
  }

  if (isOAuth(response_type)) {
    var access_token = genAccessToken();
    url = addFragment(url, "access_token", access_token);
    url = addFragment(url, "token_type", "Bearer");
    url = addFragment(url, "expires_in", "70");
    url = addFragment(url, "scope", req.query.scope);
  }

  console.log("Client remote address", req.socket.remoteAddress);

  genIdToken(
    req.socket.remoteAddress,
    req.query.client_id,
    req.query.nonce,
    access_token
  ).then((idToken) => {
    console.log("idToken", idToken);

    if (isOidc(response_type)) {
      url = addFragment(url, "id_token", idToken);
      url = addFragment(url, "session_state", "123");
    }

    res.redirect(url);
  });
});

app.get(userInfoPath, function (req, res, next) {
  const data = { ...claims };
  if (SData.has(req.socket.remoteAddress)) {
    data.sub = SData(req.socket.remoteAddress).imsi;
  }
  console.log(data);
  res.json(data);
});

app.get(endSessionPath, function (req, res, next) {
  var url = req.query.post_logout_redirect_uri;
  if (url) {
    var state = req.query.state;
    if (state) {
      url += "?state=" + state;
    }
    res.redirect(url);
  } else {
    res.send("logged out");
  }
});

app.post(userDataStorePath, jsonParser, function (req, res, next) {
  console.log(
    "User data store request from MEC controller. Received at",
    new Date().getTime()
  );
  // cut off additional subscription data
  if (req.body.subscriptionData)
    req.body.subscriptionData = req.body.subscriptionData.mainData;

  console.log(req.body);
  SData(req.body.remote_ip, req.body);
  // creating a copy for local testing
  let local_test_copy = { ...req.body };
  local_test_copy.remote_ip = "127.0.0.1";
  console.log(local_test_copy);
  SData(local_test_copy.remote_ip, local_test_copy);
  res.sendStatus(200);
});

app.get(userDataPath, (req, res, next) => {
  console.log(
    "User data requested by dataplane dispatcher for ip",
    req.query.ip
  );
  var ue_ip = req.query.ip;
  getSubscriptionData(ue_ip).then((data) => {
    console.log("Subscription data");
    console.log(data);
    res.json(data);
  });
});

app.get(validateAccessTokenPath, (req, res, next) => {
  console.log("validate access token requested");
  res.json({'status': 'OK'});
});

// Use http://localhost:15005/oidc as authority
var url = `http://${process.env.HOST_ADDR}:` + port;

prependBaseUrlToMetadata(url);

console.log("idp provider listening on " + url);

app.listen(port, "0.0.0.0");
