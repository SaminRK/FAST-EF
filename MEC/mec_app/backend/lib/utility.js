module.exports = {
  genAccessToken() {
    return parseInt(Math.random().toString().replace("0.", "")).toString(16);
  },

  verifyAccessToken(token) {
    const tokens = SData("users").map((user) => user.accessToken);
    if (tokens.includes(token)) {
      console.log("token verified");
      return true;
    } else {
      console.log("token verification failed");
      return false;
    }
  },

  getUserIdxFromImsi(imsi) {
    const users = SData("users")
    return users.findIndex( user => user.imsi === imsi)
  },

  getUeIdxFromImsi(imsi) {
    const ues = SData("ues")
    return ues.findIndex( ue => ue.imsi === imsi)
  },
};
