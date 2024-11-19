#include <string>
#include <algorithm>

std::string solution(std::string number, int k)
{
    std::string answer = "";
    int i = 0;

    for (int i = 0; i < number.size() - 1; ++i)
    {
        if (number[i] < number[i + 1])
        {
            number.erase(number.begin() + i);
            --k;
            i = -1;
        }

        if (k <= 0)
        {
            break;
        }
    }

    if (k > 0)
    {
        for (int i = k; i > 0; --i)
        {
            number.erase(number.size() - 1);
        }
    }

    answer = number;
    return answer;
}