/*
Basic Syntax of Lambda Expressions
A lambda expression has the following syntax:

cpp
Copy
[ captures ] ( parameters ) -> return_type { body }
Components of a Lambda:
Capture Clause ([captures]):

Captures variables from the surrounding scope that are used inside the lambda.
You can capture by value, by reference, or a combination of both.
Parameter List ((parameters)):

Similar to a regular function, you specify parameters that the lambda will accept.
Return Type (-> return_type):

The return type of the lambda. This part is optional if the compiler can infer it.
Body ({ body }):

The actual code that the lambda executes.

*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v = {1,2,3,4,21,2};
    for_each(v.begin(), v.end(), [](int &num){return num = num*2;});
    
    for(auto &value : v)
        cout << value << " ";    
    return 0;
}

/*###################*/

#include <iostream>

int main() {
    // Lambda that takes two integers and returns their sum
    auto add = [](int a, int b) -> int {
        return a + b;
    };

    std::cout << "Sum: " << add(3, 4) << std::endl;
    return 0;
}

