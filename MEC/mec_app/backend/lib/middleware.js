const jwt = require("jsonwebtoken");

module.exports = {
  authenticateToken(req, res, next) {
    const authHeader = req.headers["authorization"];
    const token = authHeader && authHeader.split(" ")[1];

    if (token == null) return res.sendStatus(401);

    jwt.verify(token, process.env.TOKEN_SECRET, (err, userFromJwt) => {
      console.log(err);

      if (err) return res.sendStatus(403);

      console.log("JWT token verified.");
      const users = SData("users");
      req.idx = users.findIndex((user) => user.imsi === userFromJwt.imsi);
      req.imsi = userFromJwt.imsi;

      console.log("User idx:", req.idx, " imsi:", req.imsi);

      next();
    });
  },

  e404(req, res) {
    res.type("text/plain");
    res.status(404);
    res.send("404 - Not Found");
  },

  e500(err, req, res, next) {
    console.error(err.message);
    res.type("text/plain");
    res.status(500);
    res.send("500 - Server Error");
  },
};
