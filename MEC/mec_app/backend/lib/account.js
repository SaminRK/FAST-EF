var atob = require("atob");
const axios = require("axios");

const utility = require("./utility");

module.exports = {
  saveFromIdToken(req, res) {
    // user is authenticated with OIDC from frontend

    // Now,
    //   fetch user state from other mec
    //   save user imsi
    //   notify neighbours

    console.log("Save from id token request received");

    let base64Payload = req.body.idToken.split(".")[1];
    let idTokenObj = JSON.parse(atob(base64Payload));
    const imsi = parseInt(idTokenObj.sub);
    console.log("imsi", imsi);

    const user = SData("users").filter((user) => user.imsi === imsi);
    if (user.length > 0) {
      res.json({
        message: "Already exists",
        accessToken: user[0].accessToken,
      });
    } else {
      let state = undefined;

      const accessToken = utility.genAccessToken({ imsi: imsi });

      const ueIdx = utility.getUeIdxFromImsi(imsi);
      console.log("Ue index from imsi:", ueIdx);

      const fetchState = () => {
        if (ueIdx >= 0) {
          // UE was in another MEC
          
          const mecIdToReq = SData("ues")[ueIdx].mecId;
          console.log("fetching state from MEC id", mecIdToReq);
          return axios
            .get(`${process.env.AMS_URL}/ams/fetch/state`, {
              params: {
                imsi,
                mecId: mecIdToReq,
                appId: process.env.APP_ID,
              },
            })
            .then((stateRes) => {
              // save imsi

              console.log("stateRes[data]", stateRes.data);
              return stateRes.data.state;
            });
        } else return Promise.resolve({ count: 0 });
      };

      fetchState()
        .then((state) => {
          SData("users", [
            ...SData("users"),
            {
              imsi: imsi,
              accessToken: accessToken,
              state,
            },
          ]);

          //notify neighbours

          axios
            .post(`${process.env.AMS_URL}/ams/app/notify`, {
              imsi: imsi,
              mecId: process.env.MEC_ID,
              appId: process.env.APP_ID,
            })
            .catch((error) => {
              console.log(error);
            });

          // provide access token to frontend

          res.json({
            message: "Success",
            accessToken: accessToken,
          });

          console.log("SData[users]");
          console.log(SData("users"));
          console.log("SData[ues]");
          console.log(SData("ues"));
        })
        .catch((error) => {
          console.log(error);
        });
    }
  },

  getUserAccount(req, res, next) {
    const users = SData("users");
    res.json({ imsi: users[req.idx].imsi });
  },
};
