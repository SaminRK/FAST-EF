import { makeAutoObservable } from "mobx";

class UserStore {
  imsi = "";
  accessToken = "";
  count = undefined;

  constructor() {
    makeAutoObservable(this);
  }

  updateImsi(imsi) {
    this.imsi = imsi;
  }

  updateAccessToken(accessToken) {
    this.accessToken = accessToken;
  }

  updateCount(count) {
    this.count = count;
  }
}

export default new UserStore();
