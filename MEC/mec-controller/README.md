# MEC Manager

Two parts: Controller and Manager. They work hand-in-hand.

- Controller: Listens on a TCP socket to parse S1AP messages and send UE cellular IDs to IdP.
- Manager
  - Reads subscription data from json file
  - Has route to get subscription data of a user

## Controller

Run controller

```sh
python3 mec-controller.py [-p,--prefetch] -n ( home | foreign )
```

## Manager

### API

**User subscription data request**

MEC manager reads from MEC subscriber datastore and returns user subscription data.

- Request

GET /manager/user/data/?imsi=12345678901

- Response

200 OK

```js
{
  "subscribedApps": [ 12345 ]
}
```

## AMS

AMS APIs are also included in this server.

### APIs

**App Usage Notify**

Sent by MEC app in this MEC. Notification is to be sent to proxy. 

- Request

POST /ams/app/notify

```js
{
  imsi: 12345678901,
  mecId: 5
}
```

mecId is the id of MEC which is sending this notification.

- Response

200 OK or 500 Error

**Notification of a UE using app in another MEC**

- Request

POST /ams/app/notification

```js
{
  imsi: 12345678901,
  mecId: 5,
  appId: 12345
}
```

mecId is of the MEC from which the UE is currently taking service.

- Response

200 OK or 500 Error

**App state fetch**

- Request

GET /ams/app/state/?appId=12345&imsi=123456798901&mecId=5

Here, mecId is the mec from which app state is to be fetched.

- Response

200 OK

```js
{
  state: { ... }
}
```

**Get app state from an app in this MEC**

To be requested by MEC Proxy.

- Request

GET /ams/app/state/?appId=12345&imsi=12345678901

- Response

200 OK

```js
{
  state: { ... }
}
```

Or, 404 NOT FOUND or 500 Error
