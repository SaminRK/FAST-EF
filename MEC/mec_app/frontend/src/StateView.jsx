import React, { useContext } from "react";
import { observer } from "mobx-react";
import { UserContext } from "./index";
import { updateBackendState } from "./services/Api";

const StateView = observer(() => {
  const userStore = useContext(UserContext);

  const onClick = async () => {
    userStore.updateCount(userStore.count + 1);
    await updateBackendState({ count: userStore.count });
  };

  return (
    <div>
      <p>
        You clicked {userStore.count} time {userStore.count === 1 ? "" : "s"}
      </p>
      <button onClick={onClick}>Click me!</button>
    </div>
  );
});

export default StateView;
