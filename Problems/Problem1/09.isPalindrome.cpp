#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(const string &str) 
{
    string cleanStr;        // Remove non-alphanumeric characters and convert to lowercase
    for(char c : str) 
    {
        if(isalnum(c)) 
        {
            cleanStr += tolower(c);
            cout << cleanStr;
        }
    }
    
    int n = cleanStr.size();
    for(int i = 0; i < n / 2; ++i) 
    {
        if(cleanStr[i] != cleanStr[n - i - 1]) 
        {
            return false;
        }
    }
    return true;
}

int main() 
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    
    if (isPalindrome(str)) 
    {
        cout << "The string is a palindrome." << endl;
    } else 
    {
        cout << "The string is not a palindrome." << endl;
    }
    
    return 0;
}
