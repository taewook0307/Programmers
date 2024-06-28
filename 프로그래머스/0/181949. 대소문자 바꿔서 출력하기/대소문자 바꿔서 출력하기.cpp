#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for(int i = 0; i < str.size(); ++i)
    {
        char c = str[i];
        
        if('A' <= c && 'Z' >= c)
        {
            str[i] += 32;
        }
        else if('a' <= c && 'z' >= c)
        {
            str[i] -= 32;
        }
    }
    
    cout << str;
    
    return 0;
}