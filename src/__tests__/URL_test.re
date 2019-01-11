open Jest;
open ExpectJs;

let () =
  describe("URL", () => {
    describe("constructor", () => {
      describe("make", () =>
        test("create instance properly", () =>
          expect(URL.make("https://example.org/") |> URL.toString)
          |> toBe("https://example.org/")
        )
      );

      describe("makeWithBase", () => {
        test("create instance properly with input and base", () =>
          expect(
            URL.makeWithBase("/foo", "https://example.org/") |> URL.toString,
          )
          |> toBe("https://example.org/foo")
        );

        test("create instance properly with two bases", () =>
          expect(
            URL.makeWithBase(
              "http://anotherExample.org/",
              "https://example.org/",
            )
            |> URL.toString,
          )
          |> toBe("http://anotherexample.org/")
        );
      });
    });

    describe("member variables", () => {
      let url = URL.make("https://abc:xyz@example.org:8080/foo#bar");

      describe("hash", () =>
        test("should return fragment portion of the URL", () =>
          expect(url |> URL.hash) |> toBe("#bar")
        )
      );

      describe("host", () =>
        test("should return host portion of the URL", () =>
          expect(url |> URL.host) |> toBe("example.org:8080")
        )
      );

      describe("hostname", () =>
        test("should return hostname portion of the URL", () =>
          expect(url |> URL.hostname) |> toBe("example.org")
        )
      );

      describe("href", () =>
        test("should return serialized URL", () =>
          expect(url |> URL.href)
          |> toBe("https://abc:xyz@example.org:8080/foo#bar")
        )
      );

      describe("origin", () =>
        test("should return URL's origin", () =>
          expect(url |> URL.origin) |> toBe("https://example.org:8080")
        )
      );

      describe("password", () =>
        test("should return password portion of the URL", () =>
          expect(url |> URL.password) |> toBe("xyz")
        )
      );

      describe("pathname", () =>
        test("should return path portion of the URL", () =>
          expect(url |> URL.pathname) |> toBe("/foo")
        )
      );

      describe("port", () =>
        test("should return port portion of the URL", () =>
          expect(url |> URL.port) |> toBe("8080")
        )
      );

      describe("protocol", () =>
        test("should return protocol portion of the URL", () =>
          expect(url |> URL.protocol) |> toBe("https:")
        )
      );

      describe("search", () =>
        test("should return serialized query portion of the URL", () => {
          let url = URL.make("https://abc:xyz@example.org:8080/?foo=bar");
          expect(url |> URL.search) |> toBe("?foo=bar");
        })
      );

      describe("searchParams", () =>
        test(
          "should return object repesenting the query parameters of the URL",
          () => {
          let url = URL.make("https://abc:xyz@example.org:8080/?foo=bar");
          expect(url |> URL.searchParams |> URLSearchParams.toString)
          |> toBe(
               URLSearchParams.make("?foo=bar") |> URLSearchParams.toString,
             );
        })
      );

      describe("username", () =>
        test("should return username portion of the URL", () =>
          expect(url |> URL.username) |> toBe("abc")
        )
      );
    });

    describe("instance methods", () => {
      let url = URL.make("https://abc:xyz@example.org:8080/foo#bar");
      describe("toString", () =>
        test("should return the serialized URL", () =>
          expect(url |> URL.toString)
          |> toBe("https://abc:xyz@example.org:8080/foo#bar")
        )
      );

      describe("toJSON", () =>
        test("should return the serialized URL", () =>
          expect(url |> URL.toString)
          |> toBe("https://abc:xyz@example.org:8080/foo#bar")
        )
      );
    });

    describe("instance methods", () => {
      describe("domainToASCII", () => {
        test(
          "should return the Punycode ASCII serialization of the domain", () =>
          expect(URL.domainToASCII({js|español.com|js}))
          |> toBe("xn--espaol-zwa.com")
        );

        test("should return the empty string with invalid domain", () =>
          expect(URL.domainToASCII("xn--iñvalid.com")) |> toBe("")
        );
      });

      describe("domainToUnicode", () => {
        test("should return the Unicode serialization of the domain", () =>
          expect(URL.domainToUnicode("xn--espaol-zwa.com"))
          |> toBe({js|español.com|js})
        );

        test("should return the empty string with invalid domain", () =>
          expect(URL.domainToUnicode("xn--iñvalid.com")) |> toBe("")
        );
      });

      describe("format", () => {
        let urlString = {js|https://a:b@你好你好?abc#foo|js};

        test("should return the serialized URL", () =>
          expect(URL.make(urlString) |> URL.format_)
          |> toBe("https://a:b@xn--6qqa088eba/?abc#foo")
        );

        test("should return the serialized URL excluding auth data", () =>
          expect(URL.make(urlString) |> URL.format_(~auth=false))
          |> toBe("https://xn--6qqa088eba/?abc#foo")
        );

        test("should return the serialized URL excluding search params", () =>
          expect(URL.make(urlString) |> URL.format_(~search=false))
          |> toBe("https://a:b@xn--6qqa088eba/#foo")
        );

        test("should return the serialized URL excluding fragment", () =>
          expect(URL.make(urlString) |> URL.format_(~fragment=false))
          |> toBe("https://a:b@xn--6qqa088eba/?abc")
        );

        test("should return the serialized URL with unicode", () =>
          expect(URL.make(urlString) |> URL.format_(~unicode=true))
          |> toBe({js|https://a:b@你好你好/?abc#foo|js})
        );
      });
    });
  });
