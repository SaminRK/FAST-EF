module.exports = {
  getUserIdxFromAccessToken(req, res, next) {
    const accessToken = req.headers.authorization.split(" ")[1];
    console.log('accessToken', accessToken)
    const users = SData("users")
    req.idx = users.findIndex( user => user.accessToken === accessToken)
    if (req.idx >= 0) {
      next()
    } else {
      console.log('invalid access token')
      res.type("text/plain");
      res.status(404);
      res.send("404 - Not Found");
    }
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
}