#include <algorithm>

long long GCD(long long _Num1, long long _Num2)
{
    if(_Num1 % _Num2 == 0)
    {
        return _Num2;
    }
    
    return GCD(_Num2, _Num1 % _Num2);
}

long long solution(int w,int h)
{
    long long longW = static_cast<long long>(w);
    long long longH = static_cast<long long>(h);
    
    long long answer = longW * longH;
    
    long long GCDWH = longW > longH ? GCD(longW, longH) : GCD(longH, longW);
    
    long long longWW = longW / GCDWH;
    long long longHH = longH / GCDWH;
    
    long long PartCut = (longWW * longHH) - (longWW - 1) * (longHH - 1);
    long long AllCut = PartCut * GCDWH;
    
    answer -= AllCut;
    
    return answer;
}