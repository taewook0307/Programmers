#include <vector>
#include <cmath>

int solution(std::vector<int> num_list)
{
    int answer = 0;
    
    int Sum = 0;
    int Mul = 1;
    
    for(int num : num_list)
    {
        Sum += num;
        Mul *= num;
    }
    
    answer = Mul < pow(Sum, 2) ? 1 : 0;
    
    return answer;
}