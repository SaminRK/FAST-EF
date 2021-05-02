# MEC Manager

Two parts: Controller and Manager. They work hand-in-hand.

- Controller: Listens on a TCP socket to parse S1AP messages and send UE cellular IDs to IdP.
- Manager
  - Reads subscription data from json file
  - Has route to get subscription data of a user

## Controller

Run controller

```sh
python3 controller.py [-u,--prefetch_user_data] [-s,--prefetch_state] -n ( home | foreign )
```

## Manager

### API

**User subscription data request**

MEC manager reads from MEC subscriber datastore and returns user subscription data.

- Request

GET /manager/user/data/?imsi=12345678901

- Response

200 OK

```json
{
  "mainData": {
    "subscribedApps": [ 12345 ]
  }, 
  "additional": "111..11" // 1 MB
} 
```

## AMS

AMS APIs are also included in this server.

### APIs

**App Usage Notify**

Sent by MEC app in this MEC. Notification is to be sent to proxy.

- Request

GET /ams/app/notify/?imsi=12345678901&mecId=5

mecId is the id of MEC which is sending this notification.

- Response

200 OK or 500 Error

**Notification of a UE using app in another MEC**

- Request

GET /ams/app/notification/?imsi=12345678901&mecId=5&appId=12345

mecId is of the MEC from which the UE is currently taking service.

- Response

200 OK or 500 Error

**App state fetch**

- Sent by MEC app.
- AMS checks if it knows UE's previous MEC info.

  - If yes,
    - fetches state from other MEC. (prefetching might store state locally)
    - responses state info. Set found to true.
  - Otherwise,
    - returns 404 status code. Set found to false.

- Request

GET /ams/fetch/state/?appId=12345&imsi=123456798901

- Response

200 OK

```js
{
  "found": true / false,
  "state": { ... }
}
```

**Get app state from an app in this MEC**

To be requested by MEC Proxy.

- Request

GET /ams/get/state/?appId=12345&imsi=12345678901

- Response

200 OK

```js
{
  state: { ... }
}
```

Or, 404 NOT FOUND or 500 Error

**Prefetch state for a UE**

Sent by MEC controller (manager). AMS prefetches state and saves in local data storage.

- Request

POST /ams/prefetch/state

```js
{
  "imsi": 12345678901
}
```

- Response

200 OK

## Storage

```js
{
  "users": [
    {
      "imsi": 1234567890,
      "subscriptionData": {
        "subscribedApps": [ 12345 ]
      }
    },
  ],

  "ues": [
    {
      "imsi": 12345678903,
      "mecId": 5,
      "appId": 12345,
      "state": {
        "count": 8
      }
    },
    {
      "imsi": 12345678904,
      "mecId": 9,
      "appId": 12345,
      "state": {
        "count": 10
      }
    }
  ]
}
```

`users` is used by MEC manager.

`ues` is used by AMS.
