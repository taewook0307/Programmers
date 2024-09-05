#include <string>
#include <vector>

std::vector<int> solution(int n) {
    std::vector<int> answer;
    
    answer.push_back(n);
    
    while(n != 1)
    {
        if(0 == n % 2)
        {
            n /= 2;
        }
        else
        {
            n = 3 * n + 1;
        }
        
        answer.push_back(n);
    }
    
    return answer;
}