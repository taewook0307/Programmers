#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

std::string solution(std::string s)
{
    std::string answer = "";
    
    const size_t Len = s.length();
    int Index = 0;
    
    for(size_t i = 0; i < Len; ++i)
    {
        if(s[i] == ' ')
        {
            answer += ' ';
            Index = 0;
            continue;
        }
        
        if(Index % 2 == 0)
        {
            answer += std::toupper(s[i]);
        }
        else
        {
            answer += std::tolower(s[i]);
        }
        ++Index;
    }

    return answer;
}