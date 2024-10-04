#include <iostream>

int solution(int n)
{
    int ans = 1;

    while (n != 1)
    {
        ans += (n % 2);
        n /= 2;
    }

    std::cout << ans << std::endl;
    return ans;
}