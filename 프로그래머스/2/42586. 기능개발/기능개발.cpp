#include <cmath>
#include <vector>

std::vector<int> solution(std::vector<int> progresses, std::vector<int> speeds)
{
    std::vector<int> answer;
    answer.reserve(progresses.size());

    const size_t ProgressCount = progresses.size();

    answer.push_back(1);
    int Max_Day = std::ceil((100 - progresses[0]) / static_cast<float>(speeds[0]));

    for (size_t i = 1; i < ProgressCount; ++i)
    {
        int Cur_Day = std::ceil((100 - progresses[i]) / static_cast<float>(speeds[i]));

        if (Cur_Day <= Max_Day)
        {
            ++answer.back();
        }
        else
        {
            Max_Day = Cur_Day;
            answer.push_back(1);
        }
    }

    return answer;
}