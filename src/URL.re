type t;

[@bs.module "url"] [@bs.new] external make: string => t = "URL";
[@bs.module "url"] [@bs.new]
external makeWithBase: (string, string) => t = "URL";

/* Members */
[@bs.get] [@bs.return nullable] external auth: t => option(string) = "auth";
[@bs.get] [@bs.return nullable] external hash: t => option(string) = "hash";
[@bs.get] [@bs.return nullable] external host: t => option(string) = "host";
[@bs.get] [@bs.return nullable]
external hostname: t => option(string) = "hostname";
[@bs.get] external href: t => string = "href";
[@bs.get] [@bs.return nullable]
external origin: t => option(string) = "origin";
[@bs.get] [@bs.return nullable]
external password: t => option(string) = "password";
[@bs.get] [@bs.return nullable]
external pathname: t => option(string) = "pathname";
[@bs.get] [@bs.return nullable] external port: t => option(string) = "port";
[@bs.get] [@bs.return nullable]
external protocol: t => option(string) = "protocol";
[@bs.get] [@bs.return nullable]
external search: t => option(string) = "search";
[@bs.get] [@bs.return nullable] external query: t => option(string) = "query";
[@bs.get] external searchParams: t => URLSearchParams.t = "searchParams";
[@bs.get] [@bs.return nullable]
external slashes: t => option(bool) = "slashes";
[@bs.get] [@bs.return nullable]
external username: t => option(string) = "username";

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