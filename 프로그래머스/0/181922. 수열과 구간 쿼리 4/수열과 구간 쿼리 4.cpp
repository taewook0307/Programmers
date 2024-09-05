#include <vector>

std::vector<int> solution(std::vector<int> arr, std::vector<std::vector<int>> queries)
{
    std::vector<int> answer = arr;

    for (const std::vector<int>& Query : queries)
    {
        for (int i = Query[0]; i <= Query[1]; ++i)
        {
            if (0 == i % Query[2])
            {
                ++answer[i];
            }
        }
    }

    return answer;
}