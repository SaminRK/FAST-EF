import {
  saveUserFromIdToken,
  getAccount,
  getBackendState,
} from "./services/api";

import userStore from "./UserStore";

console.log("current url", window.location.href);

const sampleIdToken =
  "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ.SflKxwRJSMeKKF2QT4fwpMeJf36POk6yJV_adQssw5c";

const idpAddr = "http://localhost:15005";

const redirectToAuth = () => {
  console.log("redirecting to idp auth endpoint");

  var authUrl = new URL(idpAddr + "/oidc/connect/authorize");

  tokenUrl.searchParams.append("response_type", "code");
  tokenUrl.searchParams.append("redirect_uri", "http://localhost:8080");
  tokenUrl.searchParams.append("state", "abc");
  window.location.replace(authUrl);
};

const redirectToToken = (code) => {
  console.log("redirecting to idp token endpoint");

  var tokenUrl = new URL(idpAddr + "/oidc/connect/token");

  tokenUrl.searchParams.append("code", code);
  tokenUrl.searchParams.append("response_type", "id_token");
  tokenUrl.searchParams.append("redirect_uri", "http://localhost:8080");
  tokenUrl.searchParams.append("state", "abc");

  window.location.replace(tokenUrl);
};

const parseQueryParam = (queryStr) => {
  const items = queryStr.split("&");
  
  let queryObj = {};

  items.forEach((item) => {
    const keyAndValue = item.split("=");
    queryObj[keyAndValue[0]] = keyAndValue[1];
  })

  return queryObj;
};

const hash = window.location.hash;
console.log("hash", hash);
const queryObj = parseQueryParam(hash.substring(1));

if ('code' in queryObj) {
  redirectToToken(queryObj.code);
} else if ('token' in queryObj) {
  
}

if (hash == "") {
  redirectToAuth();
}

saveUserFromIdToken(sampleIdToken).then(() => {
  getAccount();
  getBackendState();
});
