#include <cmath>
#include <vector>
#include <queue>

std::vector<int> solution(std::vector<int> progresses, std::vector<int> speeds)
{
    std::vector<int> answer;
    answer.reserve(progresses.size());

    const size_t ProgressCount = progresses.size();

    std::queue<int> DistributionDay;

    for (size_t i = 0; i < ProgressCount; ++i)
    {
        DistributionDay.push(std::ceil((100 - progresses[i]) / static_cast<float>(speeds[i])));
    }

    int Count = 1;
    int Condition = DistributionDay.front();
    DistributionDay.pop();

    while(1)
    {
        if(DistributionDay.empty() == true)
        {
            if (Count != 0)
            {
                answer.push_back(Count);
            }
            break;
        }

        int CurValue = DistributionDay.front();
        DistributionDay.pop();

        if (CurValue <= Condition)
        {
            ++Count;
        }
        else
        {
            answer.push_back(Count);
            Count = 1;
            Condition = CurValue;
        }
    }

    return answer;
}