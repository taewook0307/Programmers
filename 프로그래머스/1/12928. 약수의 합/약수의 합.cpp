#include <cmath>

int solution(int n)
{
    if (n < 2)
    {
        return n;
    }

    int answer = 1 + n;

    int LoopCount = sqrt(n);

    for (int i = 2; i <= LoopCount; ++i)
    {
        if (n % i == 0)
        {
            answer += i;

            if (n != i * i)
            {
                answer += n / i;
            }
        }
    }

    return answer;
}