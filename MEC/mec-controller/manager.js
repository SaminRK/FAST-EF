const express = require("express");

const fs = require("fs");
const app = express();

const dotenv = require("dotenv");
var jsonParser = require("body-parser").json();

global.SData = require("simple-data-storage");

require("custom-env").env(true);

let subscriberData;
const proxyUrl = "http://localhost:5000"

if (process.env.NETWORK === "home") {
  subscriberData = JSON.parse(fs.readFileSync("subscriberData.json"));
} else {
  subscriberData = null;
}

SData("users", subscriberData && subscriberData.users);

const port = process.env.PORT || 8000;

app.get("/user/data", (req, res) => {
  const imsi = parseInt(req.query.imsi);
  const users = SData("users");
  const user = users.filter((user) => user.imsi === imsi);
  if (user.length > 0) {
    // user data found - home network
    res.json({ subscriptinData: user[0].subscriptionData });
  } else {
    // user data not found - foreign network
    // fetch from home network
    axios
      .get(`${proxyUrl}/user/data/`, {
        params: {
          imsi: imsi,
        },
      })
      .then((userDataRes) => {
        console.log("User data received");
        console.log("Response status:", userDataRes.status);
        console.log("User data response[data]");
        console.log(userDataRes.data);
        res.json(userDataRes.data);
      })
      .catch((error) => {
        console.log("Error in Axios call");
        console.log(error);
      });
  }
});

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
