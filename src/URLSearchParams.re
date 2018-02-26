type t;

type pair('a) = (string, 'a);

/* Constructor */
[@bs.module "url"] [@bs.new] external make : string => t = "URLSearchParams";

[@bs.module "url"] [@bs.new]
external makeWithObject : Js.t({..}) => t = "URLSearchParams";

[@bs.module "url"] [@bs.new]
external makeWithArray : array(pair('a)) => t = "URLSearchParams";

/* Members */
[@bs.send.pipe : t] external append : (string, string) => unit = "";

[@bs.send.pipe : t] external delete : string => unit = "";

/* TODO: entries */
[@bs.send.pipe : t] external forEach : (pair('a) => 'b) => unit = "";

[@bs.send.pipe : t] external get : string => string = "";

[@bs.send.pipe : t] external getAll : string => array('a) = "";

[@bs.send.pipe : t] external has : string => bool = "";

/* TODO: keys */
[@bs.send.pipe : t] external set : string => string = "";

[@bs.send] external sort : t => unit = "";

[@bs.send] external toString : t => string = "";
/* values */
