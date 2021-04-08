# Proxy

## API

**App Usage Notify**

- Request
  POST /app/notify

```js
{
  appId: 12345,
  imsi: 12345678901,
  mecId: 5
}
```

mecId is the id of MEC which is sending this notification. 

- Response

200 OK

```js
{
  status: "ok";
}
```

**App state fetch**

- Request

GET /app/state?appId=12345&imsi=123456798901&mecId=5

Here, mecId is the mec from which app state is to be fetched.

- Response

200 OK

```js
{
  state: { ... }
}
```

## Storage 

Loaded from `mecInfo.json`. 