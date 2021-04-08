import React, { useContext, useEffect } from "react";
import { useAuth } from "oidc-react";
import { observer } from "mobx-react";
import { UserContext } from "./index";
import StateView from "./StateView";
import {
  getAccount,
  saveUserFromIdToken,
  getBackendState,
} from "./services/Api";

const LoggedIn = observer(() => {
  const auth = useAuth();
  const userStore = useContext(UserContext);

  useEffect(() => {
    async function getUserAccount() {
      if (auth && auth.userData) {
        console.log(auth.userData);

        const accessToken = await saveUserFromIdToken(auth.userData.id_token);
        userStore.updateAccessToken(accessToken);

        const imsi = await getAccount();
        userStore.updateImsi(imsi);

        const appState = await getBackendState();
        userStore.updateCount(appState.count);

        console.log(
          "userstore, accesstoken:",
          userStore.accessToken,
          "imsi:",
          userStore.imsi,
          "state (count):",
          userStore.count
        );
      }
    }
    getUserAccount();
  }, [auth, userStore]);

  if (auth && auth.userData) {
    return (
      <div>
        <strong>You are logged in! 🎉 IMSI: {userStore.imsi}</strong>
        <br />
        <button onClick={() => auth.signOut()}>Log out!</button>
        <StateView />
      </div>
    );
  }
  return (
    <div>Not logged in! Try to refresh to be redirected to Idp Provider.</div>
  );
});

export default LoggedIn;
