#include <vector>

std::vector<long long> solution(int x, int n)
{
    std::vector<long long> answer;
    answer.reserve(n);

    for (long long i = x; ; i += x)
    {
        answer.push_back(i);

        if (answer.size() == n)
        {
            break;
        }
    }

    return answer;
}