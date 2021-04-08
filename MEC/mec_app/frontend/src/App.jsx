import React from "react";
import "./App.css";
import { AuthProvider } from "oidc-react";
import LoggedIn from "./LoggedIn";
import { observer } from "mobx-react";

const App = observer(() => {
  const oidcConfig = {
    onSignIn: async (user) => {
      window.location.hash = "";
    },
    authority: process.env.REACT_APP_IDP_PROVIDER_AUTHORITY,
    clientId: "abcdef",
    responseType: "id_token",
    redirectUri: process.env.REACT_APP_IDP_PROVIDER_REDIRECT_URI,
  };

  return (
    <AuthProvider {...oidcConfig}>
      <div className="App">
        <header className="App-header">
          <LoggedIn />
        </header>
      </div>
    </AuthProvider>
  );
});

export default App;
