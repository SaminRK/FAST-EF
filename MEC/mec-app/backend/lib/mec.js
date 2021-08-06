const { getLargeState } = require("./utility");
const utility = require("./utility");

module.exports = {
  getMecState(req, res) {
    const imsi = parseInt(req.query.imsi);
    console.log(
      "App state request received for imsi:",
      imsi,
      "time",
      new Date().getTime()
    );

    const users = SData("users");
    const userIdx = utility.getUserIdxFromImsi(imsi);
    if (userIdx >= 0) {
      const countStr = getLargeState(userIdx);
      res.json({ countStr });
    } else {
      res.sendStatus(404);
    }
  },
};
