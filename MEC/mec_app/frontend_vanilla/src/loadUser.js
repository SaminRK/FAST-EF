import {
  saveUserFromIdToken,
  getAccount,
  getBackendState,
} from "./services/api";

console.log('current url', window.location.href);

const sampleIdToken =
  "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ.SflKxwRJSMeKKF2QT4fwpMeJf36POk6yJV_adQssw5c";

saveUserFromIdToken(sampleIdToken).then(() => {
  getAccount();
  getBackendState();
});
