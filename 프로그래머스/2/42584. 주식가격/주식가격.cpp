#include <vector>
#include <stack>

std::vector<int> solution(std::vector<int> prices)
{
    size_t PriceCount = prices.size();
    std::vector<int> answer(PriceCount, 0);

    std::stack<int> Time;
    Time.push(0);

    for (size_t i = 0; i < PriceCount; ++i)
    {
        while (false == Time.empty() && prices[Time.top()] > prices[i])
        {
            int Index = Time.top();
            Time.pop();
            answer[Index] = i - Index;
        }

        Time.push(i);
    }

    while (false == Time.empty())
    {
        int Index = Time.top();
        Time.pop();

        answer[Index] = PriceCount - 1 - Index;
    }

    return answer;
}