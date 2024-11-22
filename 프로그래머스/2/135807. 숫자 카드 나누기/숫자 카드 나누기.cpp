#include <string>
#include <vector>

int GCD(int _A, int _B)
{
    if (_A < _B)
    {
        std::swap(_A, _B);
    }

    if (0 == (_A % _B))
    {
        return _B;
    }

    return GCD(_B, _A % _B);
}

int GetGCD(const std::vector<int>& _Vector)
{
    int Result = _Vector[0];
    const size_t _VectorSize = _Vector.size();

    for (size_t i = 1; i < _VectorSize; ++i)
    {
        Result = GCD(Result, _Vector[i]);
    }

    return Result;
}

bool IsDivide(int _Divisor, const std::vector<int>& _Vector)
{
    for (int Num : _Vector)
    {
        if (0 == Num % _Divisor)
        {
            return true;
        }
    }

    return false;
}

int solution(std::vector<int> arrayA, std::vector<int> arrayB)
{
    int AGCD = -1;
    int BGCD = -1;

    if (1 == arrayA.size())
    {
        AGCD = arrayA[0];
    }
    else
    {
        AGCD = GetGCD(arrayA);
    }

    if (1 == arrayB.size())
    {
        BGCD = arrayB[0];
    }
    else
    {
        BGCD = GetGCD(arrayB);
    }

    bool AFlag = 1 != AGCD && false == IsDivide(AGCD, arrayB);
    bool BFlag = 1 != BGCD && false == IsDivide(BGCD, arrayA);

    if (false == AFlag && false == BFlag)
    {
        return 0;
    }
    else if (true == AFlag && true == BFlag)
    {
        return std::max(AGCD, BGCD);
    }
    else if (true == AFlag && false == BFlag)
    {
        return AGCD;
    }
    else
    {
        return BGCD;
    }
}