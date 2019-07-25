# multilineString
C/C++ header files for a simple multiline string concatenator.
## "Install"
Just copy the multiLineString.h(pp) file into your project folder and include it like any other file. No libraries needed.
## Usage
### C++
If you're using C++11 or above, just call ```multilineString::concat()``` from ```multiLineString.hpp``` and list the strings you want to concatenate. If you're not using C++11 or above, why not? 

Each row should be it's own argument, and the output will be a single string with newline characters between all input strings.
#### Example:
```[C++]
#include <string>
#include <iostream>
#include "multiLineString.hpp"

using namespace multilineString;
using namespace std;

string returnString(){
    return "yoted";
}

int main(){
    string s = concat(  "yeet",
                        "yote",
                        returnString().c_str()
                     );

    cout << s << endl;
    return 0;
}
```
#### Output:
```
./exec
yeet
yote
yoted
```
Note that this, just like ```printf()```, needs C-strings to work.

### C
Pure C needs to be handled a bit differently, unfortunately. Call multilineString::concat() from ```multiLineString.h```, but because C doesn't support calculating the number of variadic arguments automatically when dealing with C-strings, you have to manually tell the function how many arguments there are and what buffer to write to.
#### Example:
```[C]
#include <stdio.h>
#include "multiLineString.h"

int main(){
    char test[256] = "";
    char getStr[7] = "yoted";
    concat( test, 3,
            "yeet",
            "yote",
            getStr
          );
    printf("%s\n", test);
    return 0;
}
```
#### Output:
```
./exec
yeet
yote
yoted
```
