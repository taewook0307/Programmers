#include <string>
#include <vector>

std::string solution(std::string s)
{
    std::string answer = "";
    answer += std::toupper(s[0]);

    const int StringSize = s.size();

    for (size_t i = 1; i < StringSize; ++i)
    {
        char TopChar = answer[i - 1];

        if (TopChar == ' ')
        {
            answer += std::toupper(s[i]);
        }
        else
        {
            answer += std::tolower(s[i]);
        }
    }

    return answer;
}