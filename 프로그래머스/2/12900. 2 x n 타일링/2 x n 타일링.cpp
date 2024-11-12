#include <algorithm>

int solution(int n)
{
    if(n == 1)
    {
        return 1;
    }
    
    if(n == 2)
    {
        return 2;
    }
    
    int n1 = 1;
    int n2 = 2;
    
    for(int i = 3; i <= n; ++i)
    {
        n1 += n2;
        n1 %= 1000000007;
        std::swap(n1, n2);
    }
    
    return n2;
}