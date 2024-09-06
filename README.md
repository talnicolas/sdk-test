# Technical Test

Checkout/download this C++ 17 project and execute buildTest.bat to build it.

You can add or remove any dependency as you wish during this test.

--------

#### Exercise 1

The goal of this exercise is to review quickly the basics of C++. In the **files** folder you can find a few JSON files that contains some data regarding events sent by players playing one of our games.

You need to read those files, parse the JSON and calculate the playtime by sessionId. Please implement this in **src/exercise1.cpp**.

The [nlohmann/json](https://github.com/nlohmann/json) library has been added in the project (`src/json.hpp`) to help deal with the JSON parsing, you can replace it by any other library you would be already familiar with.

Your program should output the following to the console:

> session1: 7791 seconds played.\
> session2: 99082 seconds played.\
> session3: In progress...

#### Exercise 2

Please analyze the code in **src/exercise2.cpp** and answer the following questions:

1.	What type of constructor of std::string is called in setCustomData?
2.	What is the difference between std::unique_ptr and std::shared_ptr? 
3.	What is this code trying to achieve?
4.	Is this code correct?
5.	If the answer is no, how you can fix it?