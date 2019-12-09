type t;

type pair('a) = (string, 'a);

module Iter = {
  type t;
  type s('a) = {
    value: 'a,
    done_: bool,
  };

  [@bs.get] external value: s('a) => 'a = "value";
  [@bs.get] external done_: s('a) => bool = "done";

  [@bs.send.pipe: t] external next: unit => s('a) = "next";
};

/* Constructor */
[@bs.module "url"] [@bs.new] external make: string => t = "URLSearchParams";

[@bs.module "url"] [@bs.new]
external makeWithObject: Js.t({..}) => t = "URLSearchParams";

[@bs.module "url"] [@bs.new]
external makeWithArray: array(pair('a)) => t = "URLSearchParams";

/* Members */
[@bs.send.pipe: t] external append: (string, string) => unit = "append";
[@bs.send.pipe: t] external delete: string => unit = "delete";
[@bs.send.pipe: t] external entries: unit => Iter.t = "entries";
[@bs.send.pipe: t] external forEach: (pair('a) => 'b) => unit = "forEach";
[@bs.send.pipe: t] external get: string => string = "get";
[@bs.send.pipe: t] external getAll: string => array('a) = "getAll";
[@bs.send.pipe: t] external has: string => bool = "has";
[@bs.send.pipe: t] external keys: unit => Iter.t = "keys";
[@bs.send.pipe: t] external set: string => string = "set";
[@bs.send] external sort: t => unit = "sort";
[@bs.send] external toString: t => string = "toString";
[@bs.send.pipe: t] external values: unit => Iter.t = "values";
