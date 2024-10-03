#include <string>
#include <vector>
#include <algorithm>

std::vector<int> Factor(int _Value)
{
    if (_Value <= 0)
    {
        return std::vector<int>(0);
    }

    std::vector<int> Result;
    Result.reserve(_Value / 2);

    int N = _Value;

    for (int i = 1; i < N; ++i)
    {
        if (0 == _Value % i)
        {
            N = _Value / i;

            Result.push_back(i);

            if (i != N)
            {
                Result.push_back(N);
            }
        }
    }

    return Result;
}

int solution(int n)
{
    int answer = 0;

    // 숫자의 약수의 갯수 중 홀수의 갯수 구하기
    std::vector<int> FactorN = Factor(n);

    answer = count_if(FactorN.begin(), FactorN.end(),
        [](int _Value)
        {
            return _Value % 2 != 0;
        }
    );

    return n == 1 ? 1 : answer;
}