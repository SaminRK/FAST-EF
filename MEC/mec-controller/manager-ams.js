const express = require("express");
const axios = require("axios");

const amsRoutes = require("./lib/amsRoutes");

const fs = require("fs");
const app = express();

var jsonParser = require("body-parser").json();

global.SData = require("simple-data-storage");

require("custom-env").env(true);

let userData = null;

if (process.env.NETWORK === "home") {
  userData = JSON.parse(fs.readFileSync("userData.json"));
} else {
  userData = null;
}

SData("users", userData ? userData.users : []);
SData("ues", []);

// hard-coded ue-info , required for fetching state from cloud
// SData("ues", [
//   {
//     imsi: 1234567890,
//     mecId: 6,
//   },
//   {
//     imsi: 508931234561001,
//     mecId: 6,
//   },
// ]);

const port = process.env.PORT || 8000;

app.get("/manager/user/data", (req, res) => {
  const imsi = parseInt(req.query.imsi);
  const users = SData("users");
  const user = users.filter((user) => user.imsi === imsi);
  if (user.length > 0) {
    // user data found - home network
    const additional = "1".repeat(500000); // 500 KB
    res.json({ mainData: user[0].subscriptionData, additional });
  } else {
    // user data not found - foreign network
    // fetch from home network
    axios
      .get(`${process.env.PROXY_URL}/user/data/`, {
        params: {
          imsi: imsi,
          mecId: 5,
        },
      })
      .then((userDataRes) => {
        console.log("User data received from proxy");
        console.log("Response status:", userDataRes.status);
        // console.log("User data response[data]");
        // console.log(userDataRes.data);
        users.push({
          imsi: imsi,
          subscriptionData: userDataRes.data.mainData,
        });
        res.json(userDataRes.data);
      })
      .catch((error) => {
        console.log("Error in Axios call");
        console.log(error);
      });
  }
});

app.get("/ams/app/notify", amsRoutes.appUsageNotify);

app.get("/ams/app/notification", amsRoutes.notificationAboutUE);

app.get("/ams/fetch/state", amsRoutes.fetchAppState);

app.get("/ams/get/state", amsRoutes.getAppState);

app.post("/ams/prefetch/state", jsonParser, amsRoutes.prefetchUeState);

// custom 404 page
app.use((req, res) => {
  res.status(404);
  res.render("404");
});

// custom 500 page
app.use((err, req, res, next) => {
  console.error(err.message);
  res.status(500);
  res.render("500");
});

app.listen(port, () =>
  console.log(
    `Express started on http://localhost:${port}; ` +
      `press Ctrl-C to terminate.`
  )
);
