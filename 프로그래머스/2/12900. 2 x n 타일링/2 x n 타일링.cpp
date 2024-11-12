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
    int temp = -1;
    
    for(int i = 3; i <= n; ++i)
    {
        temp = n2;
        n2 = (n1 + n2) % 1000000007;
        n1 = temp;
    }
    return n2;
}