type t;

type pair('a) = (string, 'a);

module Iter = {
  type t;
  type s('a) = {
    value: 'a,
    done_: bool,
  };

  [@bs.get] external value : s('a) => 'a = "value";
  [@bs.get] external done_ : s('a) => bool = "done";

  [@bs.send.pipe: t] external next : unit => s('a) = "";
};

/* Constructor */
[@bs.module "url"] [@bs.new] external make : string => t = "URLSearchParams";

[@bs.module "url"] [@bs.new]
external makeWithObject : Js.t({..}) => t = "URLSearchParams";

[@bs.module "url"] [@bs.new]
external makeWithArray : array(pair('a)) => t = "URLSearchParams";

/* Members */
[@bs.send.pipe: t] external append : (string, string) => unit = "";

[@bs.send.pipe: t] external delete : string => unit = "";

[@bs.send.pipe: t] external entries : unit => Iter.t = "";

[@bs.send.pipe: t] external forEach : (pair('a) => 'b) => unit = "";

[@bs.send.pipe: t] external get : string => string = "";

[@bs.send.pipe: t] external getAll : string => array('a) = "";

[@bs.send.pipe: t] external has : string => bool = "";

[@bs.send.pipe: t] external keys : unit => Iter.t = "";

[@bs.send.pipe: t] external set : string => string = "";

[@bs.send] external sort : t => unit = "";

[@bs.send] external toString : t => string = "";

[@bs.send.pipe: t] external values : unit => Iter.t = "";
