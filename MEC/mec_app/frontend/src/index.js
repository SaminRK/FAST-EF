import React, { createContext } from "react";
import ReactDOM from "react-dom";
import "./index.css";
import App from "./App";
import userStore from "./UserStore";

export const UserContext = createContext();

ReactDOM.render(
  <React.StrictMode>
    <UserContext.Provider value={userStore}>
      <App />
    </UserContext.Provider>
  </React.StrictMode>,
  document.getElementById("root")
);
