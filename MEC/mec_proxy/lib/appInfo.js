const axios = require("axios");

module.exports = {
  appUsageNotify(req, res, next) {
    const imsi = parseInt(req.body.imsi);
    const appId = parseInt(req.body.appId);
    const sendingMecId = parseInt(req.body.mecId);
    console.log("sendingMecId", sendingMecId);

    const receivingMecs = SData("mecs").filter(
      (mec) => mec.id !== sendingMecId
    );

    console.log("receivingMecs");
    console.log(receivingMecs);

    for (let mec of receivingMecs) {
      axios
        .post(`${mec.url}/mec/app/notification/`, {
          imsi: imsi,
          mecId: sendingMecId,
        })
        .then((notifyRes) => {})
        .catch((error) => {
          console.log(error);
        });
    }

    res.json({ status: "ok" });
  },

  getAppState(req, res, next) {
    const appId = parseInt(req.query.appId);
    const imsi = parseInt(req.query.imsi);
    const mecId = parseInt(req.query.mecId);

    console.log(
      "app state request for imsi:",
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
    const mecUrl = matchedMec[0].url;

    axios
      .get(`${mecUrl}/mec/app/state/`, {
        params: {
          imsi: imsi,
        },
      })
      .then((stateRes) => {
        console.log("App state received from mecId:", mecId);
        console.log("Response status:", stateRes.status);
        console.log("state Response[data]");
        console.log(stateRes.data);
        res.json(stateRes.data);
      })
      .catch((error) => {
        console.log("Error in Axios call");
        console.log(error);
      });
  },
};
