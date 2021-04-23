const axios = require("axios");

module.exports = {
  appUsageNotify(req, res, next) {
    const imsi = parseInt(req.body.imsi);
    const appId = parseInt(req.body.appId);
    const sendingMecId = parseInt(req.body.mecId);
    console.log("sendingMecId", sendingMecId);

    axios
      .post(`${process.env.PROXY_URL}/app/notify`, {
        imsi,
        mecId: sendingMecId,
        appId,
      })
      .then((notifyRes) => {
        console.log("notifying proxy response status", notifyRes.status);
        res.sendStatus(notifyRes.status);
      })
      .catch((error) => {
        console.log(error);
      });
  },

  notificationAboutUE(req, res) {
    const imsi = req.body.imsi;
    const mecId = req.body.mecId;

    axios
      .post(`${process.env.APP_URL}/mec/app/notification/`, {
        imsi,
        mecId,
      })
      .then((notifyRes) => {
        console.log("Notifying app response status", notifyRes.status);
        res.sendStatus(notifyRes.status);
      })
      .catch((error) => {
        console.log(error);
      });
  },

  fetchAppState(req, res, next) {
    const appId = parseInt(req.query.appId);
    const imsi = parseInt(req.query.imsi);
    const mecId = parseInt(req.query.mecId);

    console.log(
      "app state request for imsi:",
      imsi,
      "to be sent to mecId:",
      mecId
    );

    // Apply prefetching here

    axios
      .get(`${process.env.PROXY_URL}/app/state`, {
        params: {
          imsi,
          mecId,
          appId,
        },
      })
      .then((stateRes) => {
        console.log("App state received from proxy");
        console.log("Response status:", stateRes.status);
        console.log("state Response[data]");
        console.log(stateRes.data);
        res.json(stateRes.data);
      })
      .catch((error) => {
        console.log(error);
      });
  },

  getAppState(req, res, next) {
    const imsi = parseInt(req.query.imsi);
    const appId = parseInt(req.query.appId);

    console.log("app state request for imsi:", imsi);

    axios
      .get(`${process.env.APP_URL}/mec/app/state`, {
        params: {
          imsi,
        },
      })
      .then((stateRes) => {
        console.log("App state received from app. Sending to proxy.");
        console.log("Response status:", stateRes.status);
        console.log("state Response[data]");
        console.log(stateRes.data);
        res.json(stateRes.data);
      })
      .catch((error) => {
        console.log(error);
      });
  },
};
