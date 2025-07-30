#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string reverseSentence(const string &sentence) 
{
    stringstream ss(sentence);
    string word;
    
    vector<string> words;
    string reversedSentence; 

    while (ss >> word)  // Split the sentence into words
    {
        words.push_back(word);
    }
   
    for (int i = words.size() - 1; i >= 0; --i) 
    {
        reversedSentence += words[i];
        if (i != 0) 
        {
            reversedSentence += " ";
        }
    }

    return reversedSentence;
}

int main() 
{
    string sentence = "Today is Sunday";
    string reversed = reverseSentence(sentence);
    cout << "Reversed sentence: " << reversed << endl;
    return 0;
}
