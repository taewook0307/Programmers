#include <bits/stdc++.h>

std::vector<int> solution(std::vector<int> sequence, int k)
{
    const size_t NumCount = sequence.size();

    std::vector<int> answer(2, -1);
    std::deque<std::pair<int, int>> Part;

    int Index = 0;
    int Sum = 0;
    int PartCount = INT_MAX;

    while (Index < NumCount)
    {
        if (Sum <= k)
        {
            Part.push_back(std::make_pair(sequence[Index], Index));
            Sum += sequence[Index];
            ++Index;

            if (Sum == k && PartCount > Part.size())
            {
                answer[0] = Part.front().second;
                answer[1] = Part.back().second;
                PartCount = Part.size();
            }
        }
        else
        {
            Sum -= Part.front().first;
            Part.pop_front();

            if (Sum == k && PartCount > Part.size())
            {
                answer[0] = Part.front().second;
                answer[1] = Part.back().second;
                PartCount = Part.size();
            }
        }
    }

    while (false == Part.empty())
    {
        if (Sum == k && PartCount > Part.size())
        {
            answer[0] = Part.front().second;
            answer[1] = Part.back().second;
            PartCount = Part.size();
        }

        Sum -= Part.front().first;
        Part.pop_front();
    }

    return answer;
}