# Documentation for AocDateLib
Hi , welcome to this repository, if you are here would say that you need way for efficently manage dates in C++ programming language.
Well, you've found what that you was searching!! 
Before venturing into the maze of this precious library, let's take a quick look at what AocDateLib really is.

# Index
- [***What is AocDateLib?***](#what-is-aocdatelib)
- [***Starting with AocDateLib***](#starting-with-aocdatelib)
  - [***How to use it***](#title3)
  - Hello1
  - Hello2
  - Hello3
- [***Title4***](#title4)
- [***Title5***](#title5)
- [***Title6***](#title6)

## What is AocDateLib?
AocDateLib is a efficent way for ***manage dates in C++***. It's based on the C/C++ time library for create dates and timestamps.
I've created this library because I think that the way in which we can work with dates in the time library is difficult to understand at first impact and it's not very intuitive. In addition this library allow take advantage from C++ functionalities(ex. classes) at the best. 
Well... It sounds interesting!! So let's going to explore this library!!

# Starting With AocDateLib

Well, we are ready to start working with AocDateLib, first of all let me tell you how to use it in the next subsection.
  
  
  
## How to use it

AocDateLib is entirely developed in C++, especially **C++20**. So to use it, we need to include the AocDateLib header file in our project, so depending on the operating system we are using, **we need to compile by linking the dynamic library** (.ddl or .so). I don't give the static library but it is easy to get it if you have minimal knowledge in C++ and on how static and dynamic libraries work.
Let's see an example of how to use the Dynamic library for compile our program. In this example we will use g++ compiler:

```
g++ -std=c++20 -c mymainfile.cpp
g++ -o myprogram mymainfile.o AocDateLib.so
./myprogram
```
> **It's important to compile in C++20 for the correct functioning of the library, in g++ compiler the flag for do this is ```-std=c++20``` but can change dipendently from the compiler.**

A more in-depth guide can be found at [this link](https://domiyanyue.medium.com/c-development-tutorial-4-static-and-dynamic-libraries-7b537656163e).




