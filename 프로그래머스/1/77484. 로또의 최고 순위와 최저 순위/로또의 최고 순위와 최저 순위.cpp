#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> lottos, std::vector<int> win_nums)
{
    std::vector<int> answer(2, -1);

    int CorrectCount = 0;
    int ZeroCount = std::count(lottos.begin(), lottos.end(), 0);

    for (int WinNum : win_nums)
    {
        if (lottos.end() != std::find(lottos.begin(), lottos.end(), WinNum))
        {
            ++CorrectCount;
        }
    }

    if (CorrectCount == 0)
    {
        answer[1] = 6;
    }
    else
    {
        answer[1] = 7 - CorrectCount;
    }

    int MaxCorrect = ZeroCount + CorrectCount;

    if (MaxCorrect == 0)
    {
        answer[0] = 6;
    }
    else
    {
        answer[0] = 7 - MaxCorrect;
    }

    return answer;
}