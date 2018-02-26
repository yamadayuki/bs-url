# bs-url

`url` module bindings for [BuckleScript](https://github.com/bloomberg/bucklescript) in [Reason](https://github.com/facebook/reason).

# Installation

1. Install `@yamadayuki/bs-url`

```sh
$ npm install --save @yamadayuki/bs-url
```

2. Add `@yamadayuki/bs-url` to `bs-dependencies` section of `bsconfig.json`.

# Usage

Create URL object.

```reason
let myURL = URL.make("https://example.com");
Js.log(myURL);
/* Prints https://example.com */

let otherURL = URL.make("/foo", "https://example.com");
Js.log(otherURL);
/* Prints https://example.com/foo */
```

Get member in URL object.

```reason
URL.make("https://example.com/foo#bar")
|> URL.hash
|> Js.log
/* Prints #bar */
```

Resove a target URL relative to a base URL.

```reason
URL.resolve("https://example.com/", "/foo") /* https://example.com/foo */
```

Create URLSearchParams object.

```reason
/* from String */
let params0 = URLSearchParmas.make("user=abc&query=xyz");

/* from Object */
let params1 = URLSearchParmas.makeWithObject({"user": "abc", "query": [|"first", "second"|]});

/* from Array */
let params2 = URLSearchParmas.makeWithArray([|("user", "abc"), ("query", "first"), ("query", "second")|])
```

# TODO

* ~~Support `URLSearchParams`~~ Done.

# Contributing

### Build

```
npm run build
```

### Build + Watch

```
npm run start
```

### Editor

If you use `vscode`, Press `Windows + Shift + B` it will build automatically
