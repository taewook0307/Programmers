#include <vector>

int solution(std::vector<int> a, std::vector<int> b)
{
    int answer = 0;
    
    const size_t Count = a.size();
    
    for(size_t i = 0; i < Count; ++i)
    {
        answer += (a[i] * b[i]);
    }
    
    return answer;
}