#include <string>
#include <vector>

std::string solution(std::vector<std::string> my_strings, std::vector<std::vector<int>> parts)
{
    std::string answer = "";
    
    const int my_stringsSize = static_cast<int>(my_strings.size());
    
    for(int i = 0; i < my_stringsSize; ++i)
    {
        int StartIndex = parts[i][0];
        int EndIndex = parts[i][1];
        
        int Length = EndIndex - StartIndex + 1;
        
        std::string SliceString = my_strings[i].substr(StartIndex, Length);
        answer += SliceString;
    }
    
    return answer;
}