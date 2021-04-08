import axios from "axios";
import { apiUrl } from "./utils";
import userStore from "../UserStore";

const makeAxiosConfig = () => ({
  headers: {
    Authorization: `Bearer ${userStore.accessToken}`,
    "Content-Type": "application/json",
  },
});

export const saveUserFromIdToken = async (idToken) => {
  console.log("apiUrl", apiUrl);

  const res = await axios.post(
    `${apiUrl}/user/save-from-id-token`,
    { idToken },
    {
      headers: {
        "Content-Type": "application/json",
      },
    }
  );
  return res.data.accessToken;
};

export const getAccount = async () => {
  const res = await axios.get(`${apiUrl}/user/account`, makeAxiosConfig());
  return res.data.imsi;
};

export const getBackendState = async () => {
  if (userStore.accessToken) {
    const res = await axios.get(`${apiUrl}/state`, makeAxiosConfig());
    if (res.data.state) {
      console.log("fetched state from backend", res.data.state);
      return res.data.state;
    }
  }
  return undefined;
};

export const updateBackendState = async (state) => {
  console.log("posting", state);
  if (userStore.accessToken) {
    await axios.post(
      `${apiUrl}/state/update`,
      { state: state },
      makeAxiosConfig()
    );
  }
};
