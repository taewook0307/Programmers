#include <vector>
#include <algorithm>

int solution(std::vector<int> d, int budget)
{
    int answer = 0;
    
    const size_t DepartmentCount = d.size();
    
    std::sort(d.begin(), d.end());
    
    int Fee = 0;
    
    for(int i = 0; i < DepartmentCount; ++i)
    {
        Fee += d[i];
        
        if(Fee <= budget)
        {
            ++answer;
        }
        else
        {
            break;
        }
    }
    
    return answer;
}