import axios from "axios";
import {API_URL} from "../constants";

const apiUrl = API_URL;

const makeAxiosConfig = () => ({
  headers: {
    Authorization: `Bearer ${window.localStorage.accessToken}`,
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
  window.localStorage.accessToken = res.data.accessToken;
  console.log("accessToken", window.localStorage.accessToken);
};

export const login = async () => {
  const res = await axios.get(`${apiUrl}/user/login`, makeAxiosConfig());

  document.getElementById("imsi").innerHTML = res.data.imsi;
  console.log("imsi", res.data.imsi);
};

export const getInitialState = async () => {
  const res = await axios.get(`${apiUrl}/initstate`, makeAxiosConfig());

  document.getElementById("count").innerHTML = res.data.state.count;
  console.log("count", res.data.state.count);
};

export const getAccount = async () => {
  const res = await axios.get(`${apiUrl}/user/account`, makeAxiosConfig());

  console.log("imsi", res.data.imsi);

  return res.data.imsi;
};

export const getBackendState = async () => {
  const res = await axios.get(`${apiUrl}/state`, makeAxiosConfig());
  if (res.data.state) {
    console.log("fetched state from backend", res.data.state);
    return res.data.state.count;
  }
};

export const updateBackendState = async (state) => {
  console.log("posting", state);

  await axios.post(
    `${apiUrl}/state/update`,
    { state: state },
    makeAxiosConfig()
  );
};
