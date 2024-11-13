#include <vector>

std::vector<long long> solution(std::vector<long long> numbers)
{
    std::vector<long long> answer;
    answer.reserve(numbers.size());

    for (long long Num : numbers)
    {
        long long Bit = 0;                        

        while (1)
        {
            if ((Num & 1LL << Bit) == 0)
            {
                break;
            }

            Bit++;
        }

        if (Bit != 0)
        {
            long long temp = 1LL << (Bit - 1);
            Num = Num + (1LL << Bit) - temp;
        }
        else
        {
            Num += 1LL << Bit;
        }

        answer.push_back(Num);
    }

    return answer;
}