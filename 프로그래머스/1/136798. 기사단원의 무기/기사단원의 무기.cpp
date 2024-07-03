#include <string>
#include <vector>

using namespace std;

int CalculateFactorCount(int number)
{
    int Result = 0;

    int CheckNumber = 0;

    for (int i = 1; i <= number; ++i)
    {
        int RemainValue = number % i;

        int DivideNumber = number / i;

        if (0 == RemainValue)
        {
            if (CheckNumber <= i
                && CheckNumber != 0)
            {
                break;
            }

            ++Result;

            if (number == DivideNumber * i
                && DivideNumber != i)
            {
                ++Result;
            }

            CheckNumber = DivideNumber;
        }
    }

    return Result;
}

int solution(int number, int limit, int power) {
    int answer = 0;

    vector<int> Factors;
    Factors.resize(number);

    for (int i = 0; i < number; ++i)
    {
        Factors[i] = CalculateFactorCount(i + 1);

        if (limit < Factors[i])
        {
            Factors[i] = power;
        }

        answer += Factors[i];
    }

    return answer;
}