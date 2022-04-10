# Use case

I love programming in C. 
But very often, I face the issue that I need some peculiar data structures (List, Trees, Dictionaries) ... that are not built-in in C standart library. So you need to write some extra code for you data structure every time. 
And as a Python developer, I like to have those structures quickly available under the hood.

# What this repo is about

I know resources to implement those data structures are widely available over the net, but I like the idea to implement them myself once again : you gain deep understanding of their functionning, you can implement them the way you want, etc.
(plus it is a good exercise to brush up on C pointer arithmetic ...)
For my side I will implement them the Python way.

# What this repo is not about

I do not intend to provide the perfect implementation. It will not even be close to perfect as this project is part of my learning journey to be a better software engineer.
I will thus try to share the resources I used, stackoverflow topics I digged in, questions I asked myself : maybe it can help over people as well.

# Data structures actually provided by this repo :

1. Dictionary (Python interface, implemented as a linked list of elements)
1. Red Black Tree (Balanced binary tree)

# Use cases examples

1. Dictionary : Parse a simple JSON file (only integer to string association) and get its content into a C dictionary.

# TODO

* Propose appropriate tests for `json_parser` lib.
* Correct error handling in `dict` and `json_parser` libs.
* Add dedicated PRINT macros in `print.h` : `PRINT_ERROR`, `PRINT_OK`, `PRINT_INFO`, `PRINT_ASSERT`.
* Choose appropriate open source license.