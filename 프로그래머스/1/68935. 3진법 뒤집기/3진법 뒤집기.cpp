#include <vector>
#include <cmath>
#include <algorithm>

int solution(int n)
{
    int answer = 0;
    
    std::vector<int> ThreeBinary;
    ThreeBinary.reserve(n / 3);
    
    while(n != 0)
    {
        ThreeBinary.push_back(n % 3);
        n /= 3;
    }
    
    std::reverse(ThreeBinary.begin(), ThreeBinary.end());
    
    size_t LoopCount = ThreeBinary.size();
    
    for(size_t i = 0; i < LoopCount; ++i)
    {
        answer += std::pow(3, i) * ThreeBinary[i];
    }
    
    return answer;
}