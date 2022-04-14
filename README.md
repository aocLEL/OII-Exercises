# Documentation for AocDateLib
Hi , welcome to this repository, if you are here would say that you need way for efficently manage dates in C++ programming language.
Well, you've found what that you was searching!! 
Before venturing into the maze of this precious library, let's take a quick look at what AocDateLib really is.

# Index
- [***What is AocDateLib?***](#what-is-aocdatelib)
- [***Starting with AocDateLib***](#starting-with-aocdatelib)
  - [***How to use it***](#how-to-use-it)
  - [***Assumptions***](#assumptions)
  - [***Are you ready?***](#ready)
- [***The Date class: heart of the library***](#the-date-class)
  - [***Create Dates***](#create-dates)
- [***Title5***](#title5)
- [***Title6***](#title6)

<br>
<br>

# What is AocDateLib?
AocDateLib is a efficent way for ***manage dates in C++***. It's based on the C/C++ time library for create dates and timestamps.
I've created this library because I think that the way in which we can work with dates in the time library is difficult to understand at first impact and it's not very intuitive. In addition this library allow take advantage from C++ functionalities(ex. classes) at the best. 
Well... It sounds interesting!! So let's going to explore this library!!

<br>

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

<br>

## Assumptions
throughout this documentation we will refer to some **keywords** regarding the library.
List these below:
- ***Error Date object*** --> This object is a Date corrisponding to **1/01/1900**. It will be returned when the desired date is not considered valid or when certain operations are not possible on it.
- **Limits of the library** --> this is not precisely a keyword but It's good immediately illustrate the limitations of the library in terms of date management. The minimum valid date is **1/01/1900 00:00:00** while the maximum valid date is, on 64bit Windows, **31/12/2999 23:59:59** while on other operating systems is **31/12/2037 23:59:59** due to the limitations of the time library and the lack of support for higher dates on unix like systems. I am not ruling out that an update to the library may arrive in the future that adds this support.


## Ready?
So , after this brief two sections we are ready to start with this library, Good luck!!

<br>
<br>

# The Date class
The Date class is the heart of this library. this class is what we create and manage our dates with. Let's not get lost in small talk and let's see now how to best use it to create our dates.

<br>

## Create dates
AocDateLib provides different ways for create dates. First of all we must obviusly create a new Date object:
```cpp
Date new_date{}; //new Date object that calls default constructor
```
This statement creates a new Date object calling the default constructor of the class. This constructor sets the date to the current date, in fact we can
output the date simply using on it the `<<` operator:
```cpp
Date new_date{};
std::cout << new_date << std::endl; //outputs the current date
```
Obviusly this isn't the only way for create dates, we can use other 2 ways:
 - We can create dates manually specifing all time datas(year, month, day, hour, minute, second):
 ```cpp
 Date custom_date{2022, 03, 27, 22, 32, 48};
 std::cout << custom_date << std::endl; //outputs: 27/03/2022 22:32:48
 ```
 - We can create dates form a string:

