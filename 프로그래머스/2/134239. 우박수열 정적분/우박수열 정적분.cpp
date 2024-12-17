#include <vector>
#include <numeric>

std::vector<double> solution(int k, std::vector<std::vector<int>> ranges)
{
    std::vector<double> answer;
    answer.reserve(ranges.size());

    std::vector<int> Collatz;
    Collatz.reserve(k);

    int Num = k;
    int n = 0;

    while (Num != 1)
    {
        Collatz.push_back(Num);

        if (1 == (Num & 1))
        {
            Num *= 3;
            ++Num;
        }
        else
        {
            Num /= 2;
        }
        
        ++n;
    }

    Collatz.push_back(1);

    for (const std::vector<int>& Range : ranges)
    {
        int Start = Range[0];
        int End = Range[1] <= 0 ? n + Range[1] : Range[1];

        if (End < Start)
        {
            answer.push_back(-1.0);
            continue;
        }

        double PushValue = 0.0;

        for (int i = Start; i < End; ++i)
        {
            PushValue += ((Collatz[i] + Collatz[i + 1]) / 2.0);
        }

        answer.push_back(PushValue);
    }

    return answer;
}