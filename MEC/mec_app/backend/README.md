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

**GET /user/login**

- Request
  Header `{ 'authorization': 'Bearer TOKEN' }`

- Response

```js
{
  imsi: 12345678901,
}
```

**GET /initstate**

- Request
  Header `{ 'authorization': 'Bearer TOKEN' }`

- Response

```js
{
  state: {
    count: 6
  }
}
```

**GET /user/account**

- Request
  Header `{ 'authorization': 'Bearer TOKEN' }`

- Response

```js
{
  imsi: 12345678901,
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

```js
{
  state: {
    count: 7;
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

**App state request**

- Request

GET /mec/app/state/?imsi=12345678901

- Response

200 OK

```js
{
  countStr: "33333....33"
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
      state: {
        count: 3,
      },
    },
    {
      imsi: 12345678902,
      state: {
        count: 1,
      },
    },
  ];
}
```

`users` array contain data of users using app from this server. `ues` array contain data from notifications of app usage from other MECs.
