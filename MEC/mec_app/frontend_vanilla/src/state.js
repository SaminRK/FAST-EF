import userStore from "./UserStore";
import { updateBackendState } from "./services/api";

const incrementCount = () => {
  userStore.updateCount(userStore.count + 1);
  updateBackendState({ count: userStore.count });
};

const buttonEl = document.getElementById("btn");
buttonEl.addEventListener("click", incrementCount);
