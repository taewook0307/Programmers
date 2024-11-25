#include <vector>

std::vector<int> solution(long long n)
{
    std::vector<int> answer;
    answer.reserve(11);

    while (n != 0)
    {
        answer.push_back(n % 10);
        n /= 10;
    }

    return answer;
}