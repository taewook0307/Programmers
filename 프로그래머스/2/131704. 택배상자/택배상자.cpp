#include <string>
#include <vector>
#include <stack>
#include <numeric>

int solution(std::vector<int> order)
{
    int answer = 0;
    
    std::stack<int> SubContainer;
    
    int StartOrder = 1;
    
    for(int OrderNum : order)
    {
        while(StartOrder < OrderNum)
        {
            SubContainer.push(StartOrder);
            ++StartOrder;
        }
        
        if(StartOrder > OrderNum && false == SubContainer.empty() && OrderNum != SubContainer.top())
        {
            break;
        }
        
        if(StartOrder == OrderNum)
        {
            ++answer;
            ++StartOrder;
        }
        
        if(false == SubContainer.empty() && OrderNum == SubContainer.top())
        {
            SubContainer.pop();
            ++answer;
        }
    }
    
    return answer;
}