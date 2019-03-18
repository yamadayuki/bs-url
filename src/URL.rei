type t;
let make: string => t;
let makeWithBase: (string, string) => t;
let hash: t => string;
let host: t => string;
let hostname: t => string;
let href: t => string;
let origin: t => string;
let password: t => string;
let pathname: t => string;
let port: t => string;
let protocol: t => string;
let search: t => string;
let searchParams: t => URLSearchParams.t;
let username: t => string;
let toString: t => string;
let toJSON: t => string;
let domainToASCII: string => string;
let domainToUnicode: string => string;
let format:
  (~auth: bool=?, ~fragment: bool=?, ~search: bool=?, ~unicode: bool=?, t) =>
  string;
let parse: string => t;
let resolve: (string, string) => t;
