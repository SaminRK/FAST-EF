const axios = require("axios");

module.exports = {
  getUserData(req, res, next) {
    const imsi = parseInt(req.query.imsi);
    const mecId = parseInt(req.query.mecId);

    console.log(
      "User data request for imsi:",
      imsi,
      "to be sent to mecId:",
      mecId
    );

    const mecs = SData("mecs");
    console.log("mecs");
    console.log(mecs);
    const matchedMec = SData("mecs").filter((mec) => mec.id === mecId);
    console.log("matchedMec");
    console.log(matchedMec);
    const mecManagerAmsUrl = matchedMec[0].managerAmsUrl;

    axios
      .get(`${mecManagerAmsUrl}/manager/user/data/`, {
        params: {
          imsi: imsi,
        },
      })
      .then((userDataRes) => {
        console.log("User data received from mecId:", mecId);
        console.log("Response status:", userDataRes.status);
        // console.log("User data");
        // console.log(userDataRes.data);
        res.json(userDataRes.data);
      })
      .catch((error) => {
        console.log("Error in Axios call");
        console.log(error);
      });
  },
};
