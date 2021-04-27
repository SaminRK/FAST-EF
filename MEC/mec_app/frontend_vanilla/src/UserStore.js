import { makeAutoObservable } from "mobx";

class UserStore {
  imsi = "";
  accessToken = "";
  count = undefined;
  redirected = false;

  constructor() {
    makeAutoObservable(this);
  }

  updateImsi(imsi) {
    this.imsi = imsi;
    document.getElementById("imsi").innerHTML = imsi;
  }

  updateAccessToken(accessToken) {
    this.accessToken = accessToken;
  }

  updateCount(count) {
    this.count = count;
    document.getElementById("count").innerHTML = this.count;
  }
}

export default new UserStore();
