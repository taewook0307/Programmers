#include <string>

std::string solution(std::string s)
{
    std::string answer = "";

    if (s.length() % 2 == 0)
    {
        int Half = s.length() / 2;
        
        answer = s.substr(Half - 1, 2);
    }
    else
    {
        int Half = s.length() / 2;
        answer = s[Half];
    }
    
    return answer;
}