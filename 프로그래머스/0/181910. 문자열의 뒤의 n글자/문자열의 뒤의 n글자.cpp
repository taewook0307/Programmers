#include <string>
#include <vector>

std::string solution(std::string my_string, int n)
{
    std::string answer = "";
    return answer = my_string.substr(my_string.size() - n, n);
}