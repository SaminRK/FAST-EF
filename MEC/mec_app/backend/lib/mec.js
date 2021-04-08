const utility = require("./utility");

module.exports = {
  notificationAboutUE(req, res) {
    const imsi = req.body.imsi;
    const mecId = req.body.mecId;

    let ues = SData("ues");
    const ueIdx = utility.getUeIdxFromImsi(imsi);

    //if ue info exists, update; else add new entry
    if (ueIdx >= 0) {
      ues[ueIdx].mecId = mecId;
      SData("ues", ues);
    } else {
      SData("ues", [...SData("ues"), { imsi, mecId }]);
    }
    console.log("Notification about UE received");
    console.log("Updated SData[ues]");
    console.log(SData("ues"));

    res.json({ status: "ok" });
  },

  getMecState(req, res) {
    const imsi = parseInt(req.query.imsi);
    console.log("App state request received for imsi:", imsi);
    
    const users = SData("users");
    const userIdx = utility.getUserIdxFromImsi(imsi);
    if (userIdx >= 0) {
      res.json({ state: users[userIdx].state });
    } else {
      res.status(404);
    }
  },
};
