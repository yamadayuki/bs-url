type t;

[@bs.module "url"] [@bs.new] external make : string => t = "URL";

[@bs.module "url"] [@bs.new]
external makeWithBase : (string, string) => t = "URL";

/* Members */
[@bs.get] external hash : t => string = "";

[@bs.get] external host : t => string = "";

[@bs.get] external hostname : t => string = "";

[@bs.get] external href : t => string = "";

[@bs.get] external origin : t => string = "";

[@bs.get] external password : t => string = "";

[@bs.get] external pathname : t => string = "";

[@bs.get] external port : t => string = "";

[@bs.get] external protocol : t => string = "";

[@bs.get] external search : t => string = "";

/* TODO: [@bs.get] external searchParams : t => string = ""; */
[@bs.get] external username : t => string = "";

/* Instance Methods */
[@bs.send] external toString : t => string = "";

[@bs.send] external toJSON : t => string = "";

/* Static methods */
[@bs.module "url"] [@bs.val] external domainToASCII : string => string = "";

[@bs.module "url"] [@bs.val] external domainToUnicode : string => string = "";

[@bs.module "url"] [@bs.val] external format : t => t = "";

[@bs.module "url"] [@bs.val]
external formatWithOption : (t, 'a) => t = "format";

[@bs.module "url"] [@bs.val] external parse : string => t = "";

[@bs.module "url"] [@bs.val] external resolve : (string, string) => t = "";
