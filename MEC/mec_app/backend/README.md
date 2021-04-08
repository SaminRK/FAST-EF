# Backend

## Run 
- Home MEC: `npm run start:home`
- Foreign MEC: `npm run start:foreign`

## APIs

### With App Frontend

**POST /user/save-from-id-token**

- Request

```js
{
  idToken: "idToken";
}
```

- Response

```js
{
  message: "Success OR Already exists",
  accessToken: "accessToken",
}
```

**GET /user/account**

- Request
  Header `{ 'authorization': 'Bearer TOKEN' }`

- Response

```js
{
  imsi: 12345678901;
}
```

**GET /state**

- Request
  Header `{ 'authorization': 'Bearer TOKEN' }`

- Response

```js
{
  state: {
    count: 5;
  }
}
```

**POST /state/update**

- Request
  Header `{ 'authorization': 'Bearer TOKEN' }`

```
{
  state: {
    count: 7
  }
}
```

- Response

```js
{
  status: "ok";
}
```

### With MEC

**Notification of a UE using app**

- Request

POST /mec/app/notification

```js
{
  imsi: 12345678901;
  mecId: 5;
}
```

mecId is of the MEC from which the UE is currently taking service.

- Response

200 OK

```js
{
  status: "ok";
}
```

**App state request**

- Request

GET /mec/app/state/?imsi=12345678901

- Response

200 OK

```js
{
  state: { ... }
}
```

Or,

404 NOT FOUND

## Storage Data Format

Sample format

```js
{
  users: [
    {
      imsi: 12345678901,
      accessToken: "7d56ac912",
      state: {
        count: 3,
      },
    },
    {
      imsi: 12345678902,
      accessToken: "218a23e0b",
      state: {
        count: 1,
      },
    },
  ],
  ues: [
    {
      imsi: 12345678903,
      mecId: 5
    },
    {
      imsi: 12345678904,
      mecId: 9
    }
  ]
}
```

`users` array contain data of users using app from this server. `ues` array contain data from notifications of app usage from other MECs.