#include <string>
#include <algorithm>

std::string solution(std::string s)
{
    std::sort(s.begin(), s.end(), std::greater<char>());
    
    return s;
}