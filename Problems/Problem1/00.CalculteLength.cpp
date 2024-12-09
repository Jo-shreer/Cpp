#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string str = "JoShreer";
    int index, len = 0;
    while(str[index] != '\0')
    {
        len++;
        index++;
    }
    cout << "Length:" << len << endl;
    return 0;
}
