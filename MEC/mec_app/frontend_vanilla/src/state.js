import { updateBackendState } from "./services/api";

const incrementCount = async (event) => {
  event.stopPropagation();
  event.preventDefault();
 
  const c = parseInt(document.getElementById("count").innerHTML);
  console.log("count", c);
  await updateBackendState({ count: c + 1 });
  document.getElementById("count").innerHTML = c + 1;
};

const buttonEl = document.getElementById("btn");
buttonEl.addEventListener("click", incrementCount);
