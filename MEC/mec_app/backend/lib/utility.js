const jwt = require("jsonwebtoken");

module.exports = {
  genAccessToken(imsi) {
    return jwt.sign(imsi, process.env.TOKEN_SECRET, { expiresIn: "86400s" });
  },

  getUserIdxFromImsi(imsi) {
    const users = SData("users")
    return users.findIndex( user => user.imsi === imsi)
  },

  getLargeState(idx) {
    const users = SData("users");
    const count = users[idx].state.count;
    const unitStr = count.toString();
    console.log("Increase factor", process.env.INCREASE_FACTOR);
    return unitStr.repeat(process.env.INCREASE_FACTOR);
  }
};
