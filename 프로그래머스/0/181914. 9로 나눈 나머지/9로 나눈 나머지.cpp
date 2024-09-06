#include <string>
#include <vector>

int solution(std::string number)
{
    int answer = 0;
    
    for(char CharDigit : number)
    {
        int Digit = CharDigit - '0';
        answer += Digit;
    }
    
    return answer % 9;
}