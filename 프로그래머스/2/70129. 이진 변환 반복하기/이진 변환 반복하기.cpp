#include <string>
#include <vector>
#include <algorithm>

std::vector<int> solution(std::string s)
{
    std::vector<int> answer;
    answer.reserve(2);

    std::string ChangeString = s;
    int Count = 0;
    int RemoveCount = 0;

    while (ChangeString != "1")
    {
        size_t Length = count(ChangeString.begin(), ChangeString.end(), '1');
        RemoveCount += ChangeString.size() - Length;

        std::string BinaryLength = "";

        while (0 != Length)
        {
            if (0 == Length % 2)
            {
                BinaryLength.push_back('0');
            }
            else
            {
                BinaryLength.push_back('1');
            }
            Length /= 2;
        }

        ChangeString = BinaryLength;
        ++Count;
    }

    answer.push_back(Count);
    answer.push_back(RemoveCount);

    return answer;
}