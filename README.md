# https://www.learncpp.com/

Back in my uni days I covered the whole thing as a prep for my OOP & SDP exams.
I want to get back in the groove and I'll cover it again.


## Impressions:
 - "You have to write a program once to know how you should have written it the first time." (Author's note 1.11)

 - "C++ is one part using what you know, and two parts looking up how to do the rest". (Second Author's note 1.11)

 - Ethymology of "Foo" (Nomenclature 2.1):
    https://datatracker.ietf.org/doc/html/rfc3092

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
