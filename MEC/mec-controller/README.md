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

# API

**User subscription data request**

- Request

GET /user/data/?imsi=12345678901

- Response

200 OK

```js
{
  "subscribedApps": [ 12345 ]
}
```
