#include <string>
#include <algorithm>

std::string solution(std::string my_string)
{
    std::string answer = my_string;
    std::reverse(answer.begin(), answer.end());
    return answer;
}