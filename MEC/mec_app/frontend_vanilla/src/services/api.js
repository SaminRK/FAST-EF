import axios from "axios";
import userStore from "../UserStore";

const apiUrl = "http://localhost:4000";

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
  userStore.accessToken = res.data.accessToken;
  console.log("accessToken", userStore.accessToken);
  
  return res.data.accessToken;
};

export const getAccount = async () => {
  const res = await axios.get(`${apiUrl}/user/account`, makeAxiosConfig());
  
  userStore.updateImsi(res.data.imsi);
  console.log("imsi", userStore.imsi);
  
  return res.data.imsi;
};

export const getBackendState = async () => {
  if (userStore.accessToken) {
    const res = await axios.get(`${apiUrl}/state`, makeAxiosConfig());
    if (res.data.state) {
      console.log("fetched state from backend", res.data.state);
      userStore.updateCount(res.data.state.count);
    }
  } else {
    console.log('access token not present?')
  }
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
