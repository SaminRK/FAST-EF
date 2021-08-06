# OIDC IdP Provider

## APIs

**User data store**

- Request

POST /oidc/store

```js
{
  "enb_ue_s1ap_id": 1234567,
  "imsi": 1234567890,
  "remote_ip": "12.1.1.2",
  "subscriptionData": {
    "subscribedApps": [ 12345 ]
  }
}
```

`subscriptionData` may not be present if prefetching is not enabled in MEC manager.

- Response

200 OK

**Get OIDC Configuration**

- Request

GET /oidc/.well-known/openid-configuration

- Response

```js
{
    "issuer": "http://localhost:15005/oidc",
    "jwks_uri": "http://localhost:15005/oidc/.well-known/jwks",
    "authorization_endpoint": "http://localhost:15005/oidc/connect/authorize",
    "userinfo_endpoint": "http://localhost:15005/oidc/connect/userinfo",
    "end_session_endpoint": "http://localhost:15005/oidc/connect/endsession"
}
```

**Authorize to get token**

- Request

  - Simple one: GET /oidc/connect/authorize?client_id=abcdef&redirect_uri=http%3A%2F%2Flocalhost%3A3000%2F&response_type=id_token&scope=openid&state=abc

  - Standard one: GET /oidc/connect/authorize?client_id=abcdef&redirect_uri=http%3A%2F%2Flocalhost%3A3000%2F&response_type=id_token&scope=openid&state=5f8d9e6abfbb4f549253845195ec138f&nonce=081e120e15c1444895bb0b99c34dd54b

- Response

Browser redirected to `redirect_uri` with tokens as fragment to the URL.

**User subscription data request**

Requested by dataplane dispatcher.

- Request

GET /user/data/?ip=12.1.1.2

- Response

200 OK

```js
{
  "subscribedApps": [ 12345 ]
}
```

**Get Signing Keys**

GET oidc/.well-known/jwks

- Response 

200 OK 

```js
{
    "keys": [
        {
            "kty": "RSA",
            "use": "sig",
            "kid": "1",
            "e": "AQAB",
            "n": "3jhVmAvS-jziIgdr3CWuPLMMrfJbaCu9ytvXp-wZCjNPegxEWopFLODKhKhBtLIfC_H6muTnFTRb1ZA6wj1J61LZqTsZRlfVvw7qjdv_gMqKp3sVyf7o1c8_-25ZcYFjBsni0YRaOKlKKRQfhR_IR521JJqViPZs2akfFn6Dl9E"
        }
    ]
}
```