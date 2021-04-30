import { saveUserFromIdToken, login, getInitialState } from "./services/api";
import { IDP_ADDR, REDIRECT_URI } from "./constants";

console.log("current url", window.location.href);

const sampleIdToken =
  "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ.SflKxwRJSMeKKF2QT4fwpMeJf36POk6yJV_adQssw5c";

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
    redirectToAuthorize();
  } else {
    await login();
    await getInitialState();
  }
} else {
  const queryObj = parseQueryParam(hash.substring(1));

  saveUserFromIdToken(queryObj.id_token).then(() => {
    await login();
    await getInitialState();
  });
}
