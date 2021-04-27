import {saveUserFromIdToken} from 'services/api';

const sampleIdToken =
  "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ.SflKxwRJSMeKKF2QT4fwpMeJf36POk6yJV_adQssw5c";

saveUserFromIdToken(sampleIdToken).then((accessToken) => {
  console.log(accessToken);
});

document.getElementById("imsi").innerHTML = 34343;
