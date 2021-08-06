const appInfo = require("./lib/appInfo");
const middleware = require("./lib/middleware");

const fs = require("fs");
const express = require("express");
const cors = require("cors");
const userData = require("./lib/userData");
var jsonParser = require("body-parser").json();

global.SData = require("simple-data-storage");

let mecInfo = JSON.parse(fs.readFileSync("mecInfo.json"));

SData("mecs", mecInfo.mecs);

const app = express();

const port = 5000;

app.use(cors());

app.get("/app/state", appInfo.getAppState);

app.get("/app/notify", appInfo.appUsageNotify);

app.get("/user/data", userData.getUserData);

// custom 404 page
app.use(middleware.e404);

// custom 500 page
app.use(middleware.e500);

app.listen(port, () =>
  console.log(
    `MEC Proxy started on http://localhost:${port}; ` +
      `press Ctrl-C to terminate.`
  )
);
