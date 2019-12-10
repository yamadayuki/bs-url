type t;
let make: string => t;
let makeWithBase: (string, string) => t;
let auth: t => option(string);
let hash: t => option(string);
let host: t => option(string);
let hostname: t => option(string);
let href: t => string;
let origin: t => option(string);
let pathname: t => option(string);
let password: t => option(string);
let port: t => option(string);
let protocol: t => option(string);
let query: t => option(string);
let search: t => option(string);
let searchParams: t => option(URLSearchParams.t);
let slashes: t => option(bool);
let username: t => option(string);
let toString: t => string;
let toJSON: t => string;
let domainToASCII: string => string;
let domainToUnicode: string => string;
let format:
  (~auth: bool=?, ~fragment: bool=?, ~search: bool=?, ~unicode: bool=?, t) =>
  string;
let parse: string => t;
let resolve: (string, string) => t;