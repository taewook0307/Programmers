#include <string>
#include <vector>
#include <algorithm>

int solution(std::vector<std::string> want, std::vector<int> number, std::vector<std::string> discount)
{
    int answer = 0;

    const size_t DiscountDays = discount.size();

    if (10 == DiscountDays)
    {
        std::vector<int> GetItem(want.size(), 0);
        const size_t CheckSize = want.size();

        for (int j = 0; j < CheckSize; ++j)
        {
            int FindIndex = find(want.begin(), want.end(), discount[j]) - want.begin();

            if (FindIndex < CheckSize)
            {
                ++GetItem[FindIndex];
            }
            else
            {
                return 0;
            }

            for (size_t k = 0; k < CheckSize; ++k)
            {
                if (number[k] > GetItem[k])
                {
                    return 0;
                }
            }
        }

        return 1;
    }

    for (size_t i = 0; i <= DiscountDays - 10; ++i)
    {
        std::vector<int> GetItem(want.size(), 0);
        const size_t CheckSize = want.size();
        
        size_t StartIndex = i;
        size_t EndIndex = i + 10;
        bool Flag = true;
        
        for (int j = StartIndex; j < EndIndex; ++j)
        {
            int FindIndex = find(want.begin(), want.end(), discount[j]) - want.begin();

            if (FindIndex < CheckSize)
            {
                ++GetItem[FindIndex];
            }
            else
            {
                Flag = false;
                break;
            }
        }

        if (false == Flag)
        {
            continue;
        }

        for (size_t k = 0; k < CheckSize; ++k)
        {
            if (number[k] > GetItem[k])
            {
                Flag = false;
                break;
            }
        }

        if (true == Flag)
        {
            ++answer;
        }
    }

    return answer;
}