import {
  saveUserFromIdToken,
  getAccount,
  getBackendState,
} from "./services/api";

const idpAddr = "http://localhost:15005";

console.log('current url', window.location.href);

const urlParams = new URLSearchParams(window.location.search);
const myParam = urlParams.get("myParam");
console.log("myParam", myParam);

var authUrl = new URL(idpAddr + "/oidc/connect/authorize");
authUrl.searchParams.append("response_type", "id_token");
authUrl.searchParams.append("redirect_uri", "http://localhost:8080/cb");
authUrl.searchParams.append("state", "abc");

window.location.replace(authUrl);

const sampleIdToken =
  "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ.SflKxwRJSMeKKF2QT4fwpMeJf36POk6yJV_adQssw5c";

saveUserFromIdToken(sampleIdToken).then(() => {
  getAccount();
  getBackendState();
});
