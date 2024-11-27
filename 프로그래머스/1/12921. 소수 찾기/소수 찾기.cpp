#include <cmath>

bool IsPrimeNum(int _Num)
{
    if(_Num < 2)
    {
        return false;
    }
    
    if(_Num < 4)
    {
        return true;
    }
    
    int LoopCount = std::sqrt(_Num);
    
    for(int i = 2; i <= LoopCount; ++i)
    {
        if(_Num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(int n)
{
    int answer = 0;
    
    for(int i = 2; i <= n; ++i)
    {
        if(true == IsPrimeNum(i))
        {
            ++answer;
        }
    }
    
    return answer;
}