import { saveUserFromIdToken, login, getInitialState } from "./services/api";
import { IDP_ADDR, REDIRECT_URI } from "./constants";

console.log("current url", window.location.href);

const redirectToAuthorize = () => {
  console.log("redirecting to idp authorize endpoint");

  var tokenUrl = new URL(IDP_ADDR + "/oidc/connect/authorize");

  tokenUrl.searchParams.append("response_type", "id_token");
  tokenUrl.searchParams.append("redirect_uri", REDIRECT_URI);
  tokenUrl.searchParams.append("state", "abc");

  window.location.replace(tokenUrl);
};

const parseQueryParam = (queryStr) => {
  const items = queryStr.split("&");

  let queryObj = {};

  items.forEach((item) => {
    const keyAndValue = item.split("=");
    queryObj[keyAndValue[0]] = keyAndValue[1];
  });

  return queryObj;
};

const hash = window.location.hash;
console.log("URL hash", hash);

if (hash === "") {
  if (window.localStorage.accessToken == null) {
    window.localStorage.redirectStart = new Date().getTime()
    console.log(
      "No access token. Redirecting to IdP. Time:",
      window.localStorage.redirectStart
    );
    redirectToAuthorize();
  } else {
    const lt = new Date().getTime();
    console.log("Login by reusing access token. Time:", lt);
    login().then(() => {
      console.log("Logged in. Login time:", new Date().getTime() - lt);
      const st = new Date().getTime();
      getInitialState().then(() => {
        console.log("Load initial state total time:", new Date().getTime() - st);
      });
    });
  }
} else {
  const lt = new Date().getTime();
  console.log("Authorized by IdP. Time:", lt, ". Auth total time:", lt - window.localStorage.redirectStart);
  const queryObj = parseQueryParam(hash.substring(1));
  saveUserFromIdToken(queryObj.id_token).then(() => {
    login().then(() => {
      console.log("Logged in. Login time:", new Date().getTime() - lt);
      const st = new Date().getTime();
      getInitialState().then(() => {
        console.log("Load initial state total time:", new Date().getTime() - st);
      });
    });
  });
}
