#include <cmath>

int CountDivisor(int _Num)
{
    if (_Num <= 2)
    {
        return _Num;
    }

    int Count = 0;

    int LoopCount = std::sqrt(_Num);

    for (int i = 1; i <= LoopCount; ++i)
    {
        if (_Num % i == 0)
        {
            if (_Num / i == i)
            {
                Count += 1;
                continue;
            }

            Count += 2;
        }
    }

    return Count;
}

int solution(int left, int right)
{
    int answer = 0;

    for (int i = left; i <= right; ++i)
    {
        if (CountDivisor(i) % 2 == 0)
        {
            answer += i;
        }
        else
        {
            answer -= i;
        }
    }

    return answer;
}