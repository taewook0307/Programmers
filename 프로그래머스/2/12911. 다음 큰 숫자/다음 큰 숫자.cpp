#include <string>
#include <cmath>
#include <bitset>
#include <algorithm>

int solution(int n)
{
    int answer = n;

    int FindLastOne = -1;
    for (int i = 1; i < n; i = i << 1)
    {
        if (i == (n & i))
        {
            FindLastOne = i;
            break;
        }
    }

    answer += FindLastOne;

    int AnswerNorN = answer ^ n;
    
    std::bitset<32> Bit(AnswerNorN);
    std::string BitString = Bit.to_string();

    int Count = count(BitString.begin(), BitString.end(), '1');
    Count -= 2;

    if (0 == Count)
    {
        return answer;
    }

    int PlusValue = 0;

    for (int i = 0; i < Count; ++i)
    {
        PlusValue += pow(2, i);
    }
    
    answer += PlusValue;

    return answer;
}