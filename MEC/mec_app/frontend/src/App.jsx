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
    authority: "http://localhost:15005/oidc",
    clientId: "abcdef",
    responseType: "id_token",
    redirectUri: "http://localhost:3000/",
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
