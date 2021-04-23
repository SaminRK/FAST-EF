const utility = require("./utility");

module.exports = {
  notificationAboutUE(req, res) {
    const imsi = req.body.imsi;
    const sendingMecId = req.body.mecId;

    let ues = SData("ues");
    const ueIdx = utility.getUeIdxFromImsi(imsi);

    //if ue info exists, update; else add new entry
    if (ueIdx >= 0) {
      ues[ueIdx].mecId = sendingMecId;
      SData("ues", ues);
    } else {
      SData("ues", [...SData("ues"), { imsi, mecId: sendingMecId }]);
    }
    console.log("Notification about UE received");
    console.log("Updated SData[ues]");
    console.log(SData("ues"));

    res.sendStatus(200);
  },

  getMecState(req, res) {
    const imsi = parseInt(req.query.imsi);
    console.log("App state request received for imsi:", imsi);
    
    const users = SData("users");
    const userIdx = utility.getUserIdxFromImsi(imsi);
    if (userIdx >= 0) {
      res.json({ state: users[userIdx].state });
    } else {
      res.sendStatus(404);
    }
  },
};
