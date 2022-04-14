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
  - [***Getting and setting date informations***](#getting-and-setting-date-informations)
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
 We can omit last three values(hour, minute, second), in this case they assume the value 0 by default
 - We can create dates form a string:
 ```cpp
 Date string_date{"21/07/2007"}; // hour, minute and second become 0 by default
 std::cout << string_date << std::endl; //outputs: 21/07/2007 00:00:00
 ```
 We can give to constructor either a std::string object or a c-like string.
 
> Note that if a time value or string is invalid, the date become a [***Error Date object***](#assumptions).

There is another important functionality: We can pass to constructor for string dates a second parameter that specifies the format of the string date:
```cpp
Date fstring_date{"07/21/2007", "%m/%d/%Y"}; //creates a string date in the format: month/day/year
Date fstring_date2{"07/21/2007 00:00:00", "%m/%d/%Y %H:%M:%S"}; //format: month/day/year hour:minute:second
```
The format qualifiers are:
- `%d` for day
- `%m` for month
- `%Y` for year
- `%H` for hour
- `%M` for minute
- `%S` for second

**Other qualifiers will simply be ignored.**

In addition we can use other separators for the date string and the format string, these don't have to be the same, they can even be mixed.
Accepted separators are: ' ', /, -, ., :  This is an example:
```cpp
Date d2{"07-21-2007 00:00-00", "%m-%d-%Y %H:%M-%S"};
std::cout << d2 << std::endl;
```
Note that when a format string isn't specified , the **default format** is `%d/%m/%Y %H:%M:%S` therefore different separators aren't accepted and they will simply be ignored throwing a Date Error 3. For use different separators/qualifiers **we must specify the string format**:
```cpp
Date d1{"21-07-2007"}; //Invalid date, string not match her default format part: %d/%m/%Y 
Date d2{"21/07/2007"}; //OK
Date d3{"21-07-2007", "%d-%m-%Y"}; //OK
Date d4{"07/21.2007 00-00:00", "%m-%d/%Y %H-%M:%S"}; //Invalid date, string not match the format(different separators)
Date d5{"07-21-2007", "%m-%d-%Y %H.%M.%S"}; //OK, the part of the string match the her format part(07-21-2007 with %m-%d-%Y)

```

> ***Note that the date output will automatically assume the format specified in initialization if one has been specified, otherwise the default will be adopted: `%d/%m/%Y %H:%M:%S`***

> ***The format can't be changed after date initizialization***

> ***IMPORTANT: The format of the current date created with the default constructor and the format for an Error Date object can't be speicified, the default will be adopted: `%d/%m/%Y %H/%M/%S`***

> ***For get the format of a date we can use the membrer function `get_format()`***


**Let's see an example that summarize everything we said:**
```cpp
#include <iostream>
#include <string>
#include "AocDateLib.h"

int main() {
  Date new_date{2021, 1, 1}; //date 1/01/2021 00:00:00, default format
  Date new_date{2021, 02, 1, 0, 0, 0, "%m-%d-%Y %H.%M.%S"}; //date 02-1-2021 00.00.00 , custom format
  
  Date d1{}, d2{"21/07/2007"}; //current date and custom string date, match with default format
  Date d3{"21-07-2007 20.45.12", "%d-%m-%Y %H.%M.%S"}; //the same date 20h 45m 12s after, match the custom format
  Date d4{"08:21:2007 00 00 00"}; //same date 1 day after. This don't match de default format, DATE ERROR 3, date become 1/01/1900 00:00:00
  
  std::string date_str{"21-07-2007"}, format_str{"%d-%m-%Y"};
  Date d5{date_str, format_str}; //date 21-07-2007 with custom format. With std::string objects
  
  std::cout << d5 << std::endl; //outputs: 21-07-2007
  return 0;
}
```

> ***Note that in the last case the custom format specifies only the day, month and year therefore it will not be possible to print the other data as well. For this reason I always recommend using a complete format string.***


<br>

## Getting and setting date informations

after creating a date we could want to getting the time values for using these in expressions , for example, for compare the day of a date with that of another. Well, AocDateLib provides , for each time value a getter member function (of the Date class). These are listed follow:
- `get_year()` --> returns the year
- `get_mon()`  --> returns the month
- `get_day()`  --> returns the day
- `get_hour()` --> returns the hour
- `get_min()`  --> returns the minute
- `get_sec()`  --> returns the second

Let's see this functions in the following snippet:
```cpp
Date new_date{}; //initzialize the Date object with the current day
unsigned int day{new_date.get_day()}, mon{new_date.get_mon()};
if(day > 14) std::cout << "The second week of the current month is passed" << std::endl;
if(mon > 6) std::cout << You've passed the half of the year" << std::endl;
```


Obviulsy we would also can modify the time values such as the day or the year. Well , AocDateLib provide for each time value a setter member function too. These are listed follwing:
- `set_year(unsigned int year)`   --> set the year to `year`
- `set_mon(unsigned int month)`   --> set the month to `month`
- `set_day(unsigned int day)`     --> set the day to `day`
- `set_hour(unsigned int hour)`   --> set the hour to `hour`
- `set_min(unsigned int minute)`  --> set the minute to `minute`
- `set_sec(unsigned int second)`  --> set the second to `second`

