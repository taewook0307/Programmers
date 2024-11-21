#include <string>
#include <vector>

double solution(std::vector<int> arr)
{
    double answer = 0;
    
    int Sum = 0;
    
    for(int Num : arr)
    {
        Sum += Num;
    }
    
    answer = static_cast<double>(Sum) / arr.size();
    
    return answer;
}