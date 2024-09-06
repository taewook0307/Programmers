#include <string>
#include <vector>

std::string solution(std::string my_string, std::vector<int> index_list)
{
    std::string answer = "";
    
    const int IndexListSize = static_cast<int>(index_list.size());
    for(int i = 0 ; i < IndexListSize; ++i)
    {
        answer += my_string[index_list[i]];
    }
    
    return answer;
}