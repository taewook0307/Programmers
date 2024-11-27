#include <string>

int solution(std::string t, std::string p)
{
    int answer = 0;
    
    const size_t tLen = t.length();
    const size_t pLen = p.length();
    
    for(size_t i = 0; i <= tLen - pLen; ++i)
    {
        std::string CheckString = t.substr(i, pLen);
        
        if(CheckString <= p)
        {
            ++answer;
        }
    }
    
    return answer;
}