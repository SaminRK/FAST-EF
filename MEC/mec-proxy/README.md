# Proxy

## API

**App Usage Notify**

- Request
  GET /app/notify/?appId=12345&imsi=12345678901&mecId=5

mecId is the id of MEC which is sending this notification.

- Response

200 OK

```js
{
  status: "ok";
}
```

**App state fetch**

Requested by one MEC to fetch state from another MEC.

- Request

GET /app/state/?appId=12345&imsi=123456798901&mecId=5

Here, mecId is the mec from which app state is to be fetched.

- Response

200 OK

```js
{
  state: { ... }
}
```

**User data fetch**

- Request

GET /user/data/?imsi=123456798901&mecId=5

Here, mecId is the mec from which user data is to be fetched.

- Response

200 OK

```js
{
  subscriptionData: {
    "subscribedApps": [ 12345 ]
  }
}
```

## Storage

Loaded from `mecInfo.json`.
