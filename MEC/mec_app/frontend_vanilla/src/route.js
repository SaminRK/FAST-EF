import userStore from "./UserStore";

const idpAddr = "http://localhost:15005";

var routes = [
  {
    path: "/",
    callback: () => {
      console.log("path /");
      // const urlParams = new URLSearchParams(window.location.search);
      const urlParams = new URLSearchParams(window.location.hash);
      console.log("urlParams", urlParams);

      const redirected = userStore.redirected;
      console.log("redirected", redirected);

      if (redirected === false) {
        console.log("redirecting to idp");

        var authUrl = new URL(idpAddr + "/oidc/connect/authorize");
        authUrl.searchParams.append("response_type", "id_token");
        authUrl.searchParams.append("redirect_uri", "http://localhost:8080");
        authUrl.searchParams.append("state", "abc");

        userStore.redirected = true;
        window.location.replace(authUrl);
      }
    },
  },
  {
    path: "/code/cb",
    callback: () => {
      console.log("path /code/cb");
      const urlParams = new URLSearchParams(window.location.hash);
      console.log("urlParams", urlParams);
    },
  },
  {
    path: "/token/cb",
    callback: () => {
      console.log("path /token/cb");
      const urlParams = new URLSearchParams(window.location.hash);
      console.log("urlParams", urlParams);
    },
  },
];

const routing = () => {
  var path = window.location.pathname;
  console.log("path", path);

  var route = routes[0];
  //Find matching route
  for (let i = 0; i < routes.length; i++) {
    var testRoute = routes[i];
    if (path === testRoute.path) {
      route = testRoute;
    }
  }

  route.callback();
};

window.addEventListener("popstate", routing);
