type t;

[@bs.module "url"] [@bs.new] external make: string => t = "URL";
[@bs.module "url"] [@bs.new]
external makeWithBase: (string, string) => t = "URL";

/* Members */
[@bs.get] external getHash: t => string = "hash";
[@bs.get] external getHost: t => string = "host";
[@bs.get] external getHostname: t => string = "hostname";
[@bs.get] external getHref: t => string = "href";
[@bs.get] external getOrigin: t => string = "origin";
[@bs.get] external getPassword: t => string = "password";
[@bs.get] external getPathname: t => string = "pathname";
[@bs.get] external getPort: t => string = "port";
[@bs.get] external getProtocol: t => string = "protocol";
[@bs.get] external getSearch: t => string = "search";
[@bs.get] external getSearchParams: t => URLSearchParams.t = "searchParams";
[@bs.get] external getUsername: t => string = "username";

/* Instance Methods */
[@bs.send] external toString: t => string = "toString";
[@bs.send] external toJSON: t => string = "toJSON";

/* Static methods */
[@bs.module "url"] [@bs.val]
external domainToASCII: string => string = "domainToASCII";
[@bs.module "url"] [@bs.val]
external domainToUnicode: string => string = "domainToUnicode";
[@bs.module "url"] [@bs.val]
external formatInternal:
  (
    t,
    {
      .
      "auth": bool,
      "fragment": bool,
      "search": bool,
      "unicode": bool,
    }
  ) =>
  string =
  "format";

let unwrapOptWithDefault = (optionalValue, default) =>
  switch (optionalValue) {
  | Some(v) => v
  | None => default
  };

let format = (~auth=?, ~fragment=?, ~search=?, ~unicode=?, t) =>
  formatInternal(
    t,
    {
      "auth": unwrapOptWithDefault(auth, true),
      "fragment": unwrapOptWithDefault(fragment, true),
      "search": unwrapOptWithDefault(search, true),
      "unicode": unwrapOptWithDefault(unicode, false),
    },
  );
[@bs.module "url"] [@bs.val] external parse: string => t = "parse";
[@bs.module "url"] [@bs.val]
external resolve: (string, string) => t = "resolve";
