#include <string>
#include <vector>

std::vector<int> solution(std::vector<std::string> intStrs, int k, int s, int l)
{
    std::vector<int> answer;
    
    for(const std::string& CurString : intStrs)
    {
        std::string SliceString = CurString.substr(s, l);
        
        int Value = stoi(SliceString);
        
        if(k < Value)
        {
            answer.push_back(Value);
        }
    }
    
    return answer;
}