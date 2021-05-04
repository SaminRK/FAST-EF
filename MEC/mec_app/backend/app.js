const loadUser = require("./lib/loadUser");
const middleware = require("./lib/middleware");
const state = require("./lib/state");
const mec = require("./lib/mec");

const express = require("express");
const cors = require("cors");
var jsonParser = require("body-parser").json();

global.SData = require("simple-data-storage");

require("custom-env").env(true);

const app = express();

const port = process.env.PORT || 4000;

SData("users", []);

app.use(cors());

app.use(express.static(__dirname + "/public"));

app.post("/user/save-from-id-token", jsonParser, loadUser.saveFromIdToken);

app.get("/mec/app/state", mec.getMecState);

app.use(middleware.authenticateToken);

app.get("/user/login", loadUser.login);

app.get("/initstate", loadUser.getInitialState);

app.get("/user/account", loadUser.getUserAccount);

app.get("/state", state.getState);

app.post("/state/update", jsonParser, state.updateState);

// custom 404 page
app.use(middleware.e404);

// custom 500 page
app.use(middleware.e500);

app.listen(port, () =>
  console.log(
    `Express started on http://localhost:${port}; ` +
      `press Ctrl-C to terminate.`
  )
);
