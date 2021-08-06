module.exports = {
  getState(req, res) {
    const users = SData("users");
    console.log("App state requested");
    console.log("User index:", req.idx, "App state:", users[req.idx].state);
    res.json({ state: users[req.idx].state });
  },

  updateState(req, res, next) {
    const state = req.body.state;
    console.log("state", state);
    let users = SData("users");
    users[req.idx] = { ...users[req.idx], state: state };
    res.json({ status: "ok" });
  },
};
