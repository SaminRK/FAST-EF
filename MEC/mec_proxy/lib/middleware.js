module.exports = { 
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