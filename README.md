# https://www.learncpp.com/

Back in my uni days I covered the whole thing as a prep for my OOP & SDP exams.
I want to get back in the groove and I'll cover it again.

Tracking my progress and doing all the problems.

## Mini projects:
 - 15.x: Random monster generator

## Impressions:
 - "You have to write a program once to know how you should have written it the
first time." (Author's note 1.11)

 - "C++ is one part using what you know, and two parts looking up how to do the
rest". (Second Author's note 1.11)

 - Ethymology of "Foo" (Nomenclature 2.1):
    https://datatracker.ietf.org/doc/html/rfc3092

 - "Our stance is that it’s better to be correct than fast, and better to fail
at compile time than runtime." (Best practice for integral types 4.6) 

 - "Language designers have a philosophy: never use a small word where a big one
will do." (Author's note 14.1)


## Notes:

 - [[maybe_unused]] attribute

Turn off compiler warning
```
[[maybe_unused]] double pi { 3.14159 };  // Don't complain if pi is unused 
```

https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/


 - "-I" compiler option

Specify alternate include directory
```
g++ -o main -I./source/includes main.cpp
```

https://www.learncpp.com/cpp-tutorial/header-files/

 - &lt;cstddef&gt; header

sizeof doesn't require a header but std::size_t does. cstddef is a good minimal
clutter option

```
#include <cstddef>  // std::size_t
```
https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/

 - "std::ws" input manipulator

Cool way to ignore leading whitespaces (since operator>> clears leading
whitespaces and std::getline() doesn't)
```
std::getline(std::cin >> std::ws, name); // read a full line of text into name
```
https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/

 - operator! implicitly converts its operand to bool

which means it's a cool way to cast:

instead of static_cast&lt;bool&gt;(foo) one can use !!foo
```
if (!!a != !!b != !!c) // a XOR b XOR c, for any type that can be converted to bool
```
https://www.learncpp.com/cpp-tutorial/logical-operators/

 - alternative operator representation is a thing

    operators like &&, &=, ^, ... have alternatives like "and", "and_eq", "xor"

```
std::cout << !a && (b || c);
std::cout << not a and (b or c);
```

https://www.learncpp.com/cpp-tutorial/logical-operators/
https://en.cppreference.com/cpp/language/operator_alternative

 - [[fallthrough]] attribute

Modifies a null statement to indicate fallthrough is intentional in a switch

```
[[fallthrough]]; // intentional fallthrough -- note the semicolon to indicate the null statement
```
https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/

 - std::common_type and std::common_type_t

Return the common type of two types.

```
std::common_type_t<int, double>  // returns int
```
https://www.learncpp.com/cpp-tutorial/arithmetic-conversions/

 - consteval trick

Force compile time function execution without making the function consteval

```
// C++20 version per Jan Scultke (https://stackoverflow.com/a/77107431/460250)
#define CONSTEVAL(...) [] consteval { return __VA_ARGS__; }()
```
https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-3-and-consteval/

 - std::to_underlying()
 
Defined in &lt;utility&gt;. Converts an enumeration to its underlying type. Equivalent to:

return static_cast<std::underlying_type_t<Enum>>(e);

```
std::cout << std::to_underlying(color) << '\n'; // convert to underlying type, will print 1 (C++23)
```

https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/

 - auto i{0Z}

In C++23, the Z suffix can be used to define a literal of the type that
is the signed counterpart to std::size_t (probably std::ptrdiff_t):

```
for (auto index{ 0Z }; index < static_cast<std::ptrdiff_t>(arr.size()); ++index)
```

https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
