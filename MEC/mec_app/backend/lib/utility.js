const jwt = require("jsonwebtoken");

module.exports = {
  genAccessToken(imsi) {
    return jwt.sign(imsi, process.env.TOKEN_SECRET, { expiresIn: "86400s" });
  },

  getUserIdxFromImsi(imsi) {
    const users = SData("users")
    return users.findIndex( user => user.imsi === imsi)
  },
};
