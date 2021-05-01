const axios = require("axios");

module.exports = {
  appUsageNotify(req, res, next) {
    const imsi = parseInt(req.query.imsi);
    const appId = parseInt(req.query.appId);
    const sendingMecId = parseInt(req.query.mecId);
    console.log("sendingMecId", sendingMecId);

    const receivingMecs = SData("mecs").filter(
      (mec) => mec.id !== sendingMecId
    );

    console.log("receivingMecs");
    console.log(receivingMecs);

    for (let mec of receivingMecs) {
      axios
        .get(`${mec.managerAmsUrl}/ams/app/notification/`, {
          params: {
            imsi,
            mecId: sendingMecId,
            appId,
          },
        })
        .then((notifyRes) => {
          console.log(
            "Received notification response from AMS. Status",
            notifyRes.status
          );
          res.sendStatus(notifyRes.status);
        })
        .catch((error) => {
          console.log(error);
        });
    }
  },

  getAppState(req, res, next) {
    const appId = parseInt(req.query.appId);
    const imsi = parseInt(req.query.imsi);
    const mecId = parseInt(req.query.mecId);

    console.log(
      "App state request for imsi:",
      imsi,
      "to be sent to mecId:",
      mecId
    );

    const mecs = SData("mecs");
    console.log("mecs");
    console.log(mecs);
    const matchedMec = SData("mecs").filter((mec) => mec.id === mecId);
    console.log("matchedMec");
    console.log(matchedMec);
    const managerAmsUrl = matchedMec[0].managerAmsUrl;

    axios
      .get(`${managerAmsUrl}/ams/get/state/`, {
        params: {
          imsi,
          appId,
        },
      })
      .then((stateRes) => {
        console.log("App state received from AMS of mecId:", mecId);
        console.log("Response status:", stateRes.status);
        // console.log("state Response[data]");
        // console.log(stateRes.data);
        res.json(stateRes.data);
      })
      .catch((error) => {
        console.log("Error in Axios call");
        console.log(error);
      });
  },
};
