#include <string>
#include <vector>
#include <algorithm>

std::string solution(std::string my_string, std::vector<std::vector<int>> queries)
{
    std::string answer = my_string;

    for (const std::vector<int>& Query : queries)
    {
        int ChangeSize = Query[1] - Query[0] + 1;
        std::string ReversePart = answer.substr(Query[0], ChangeSize);

        std::reverse(ReversePart.begin(), ReversePart.end());

        answer.replace(Query[0], ChangeSize, ReversePart);
    }

    return answer;
}