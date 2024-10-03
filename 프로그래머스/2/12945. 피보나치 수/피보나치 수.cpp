#include <vector>

std::vector<int> FibonacciValue;

int Fibonacci(int _Num)
{
    if (0 == _Num)
    {
        if (FibonacciValue.size() == 0)
        {
            FibonacciValue.push_back(0);
        }
        return 0;
    }

    if (1 == _Num)
    {
        if (FibonacciValue.size() == 1)
        {
            FibonacciValue.push_back(1);
        }
        return 1;
    }

    if (FibonacciValue.size() >= _Num + 1)
    {
        return FibonacciValue[_Num];
    }

    int Result = Fibonacci(_Num - 2) + Fibonacci(_Num - 1);
    FibonacciValue.resize(_Num + 1);
    FibonacciValue[_Num] = Result % 1234567;

    return FibonacciValue[_Num];
}

int solution(int n)
{
    int FibonacciN = Fibonacci(n);

    return FibonacciN % 1234567;
}