const axios = require("axios");

module.exports = {
  appUsageNotify(req, res, next) {
    const imsi = parseInt(req.query.imsi);
    const appId = parseInt(req.query.appId);
    const sendingMecId = parseInt(req.query.mecId);
    console.log("sendingMecId", sendingMecId);

    axios
      .get(`${process.env.PROXY_URL}/app/notify`, {
        params: {
          imsi,
          mecId: sendingMecId,
          appId,
        },
      })
      .then((notifyRes) => {
        console.log("notifying proxy response status", notifyRes.status);
        res.sendStatus(notifyRes.status);
      })
      .catch((error) => {
        console.log(error);
      });
  },

  notificationAboutUE(req, res) {
    const imsi = parseInt(req.query.imsi);
    const sendingMecId = parseInt(req.query.mecId);
    const appId = parseInt(req.query.appId);

    let ues = SData("ues");
    const ueIdx = ues.findIndex((ue) => ue.imsi === imsi);

    //if ue info exists, update; else add new entry
    if (ueIdx >= 0) {
      ues[ueIdx].mecId = sendingMecId;
      SData("ues", ues);
    } else {
      SData("ues", [...SData("ues"), { imsi, mecId: sendingMecId, appId }]);
    }

    console.log("Notification about UE received. time", new Date().getTime());
    console.log("Updated SData[ues]");
    console.log(SData("ues"));

    res.sendStatus(200);
  },

  fetchAppState(req, res, next) {
    const appId = parseInt(req.query.appId);
    const imsi = parseInt(req.query.imsi);
    const ues = SData("ues");
    const ueIdx = ues.findIndex((ue) => ue.imsi === imsi);

    //if ue info exists, fetch state; else return found = false
    if (ueIdx >= 0) {
      // Check if state is prefetched
      if ("state" in ues[ueIdx]) {
        console.log("State already prefetched");
        res.json({ found: true, state: ues[ueIdx].state });
      } else {
        const mecId = ues[ueIdx].mecId;
        console.log(
          "app state request for imsi:",
          imsi,
          "to be sent to mecId:",
          mecId
        );

        axios
          .get(`${process.env.PROXY_URL}/app/state`, {
            params: {
              imsi,
              mecId,
              appId,
            },
          })
          .then((stateRes) => {
            console.log("App state received from proxy");
            console.log("Response status:", stateRes.status);
            // console.log("state Response[data]");
            // console.log(stateRes.data);
            res.json({ found: true, state: stateRes.data });
          })
          .catch((error) => {
            console.log(error);
          });
      }
    } else {
      res.json({ found: false });
    }
  },

  getAppState(req, res, next) {
    const imsi = parseInt(req.query.imsi);
    const appId = parseInt(req.query.appId);

    console.log("app state request for imsi:", imsi);

    axios
      .get(`${process.env.APP_URL}/mec/app/state`, {
        params: {
          imsi,
        },
      })
      .then((stateRes) => {
        console.log("App state received from app. Sending to proxy.");
        console.log("Response status:", stateRes.status);
        // console.log("state Response[data]");
        // console.log(stateRes.data);
        res.json(stateRes.data);
      })
      .catch((error) => {
        console.log(error);
      });
  },

  prefetchUeState(req, res, next) {
    const imsi = parseInt(req.body.imsi);
    console.log("Prefetch state request received for IMSI", imsi);

    let ues = SData("ues");
    const ueIdx = ues.findIndex((ue) => ue.imsi === imsi);

    // Check if AMS knows about UE's previous MEC
    if (ueIdx >= 0) {
      const st = new Date().getTime();
      console.log("Prefetching app state start. time", st);

      const mecId = ues[ueIdx].mecId;
      const appId = ues[ueIdx].appId;

      axios
        .get(`${process.env.PROXY_URL}/app/state`, {
          params: {
            imsi,
            mecId,
            appId,
          },
        })
        .then((stateRes) => {
          console.log(
            "App state prefetched. Total time",
            new Date().getTime() - st
          );
          console.log("Response status:", stateRes.status);
          // console.log("state Response[data]");
          // console.log(stateRes.data);
          ues[ueIdx].state = stateRes.data;
        })
        .catch((error) => {
          console.log(error);
        });
    }

    res.sendStatus(200);
  },
};
