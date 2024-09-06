#include <iostream>
#include "json.hpp"

/*
The goal of this exercise is to review quickly the basics of C++. In the files folder you can find 
a few JSON files that contains some data regarding events sent by players playing one of our games.

You need to read those files, parse the JSON and calculate the playtime by sessionId. 

The [nlohmann/json](https://github.com/nlohmann/json) library has been added in the project (`src/json.hpp`) 
to help deal with the JSON parsing, you can replace it by any other library you would be already familiar with.

Your program should output the following to the console:

> session1: 7791 seconds played.
> session2: 99082 seconds played.
> session3: In progress...
*/

using json = nlohmann::json;

int main() {
    
    std::cout << "Good test!" << std::endl;

    return 0;
}