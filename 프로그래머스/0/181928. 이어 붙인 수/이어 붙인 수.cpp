#include <string>
#include <vector>

int solution(std::vector<int> num_list)
{
    int answer = 0;
    
    std::string EvenNum;
    std::string OddNum;
    
    for(int num : num_list)
    {
        if(0 == num % 2)
        {
            EvenNum += std::to_string(num);
        }
        else
        {
            OddNum += std::to_string(num);
        }
    }
    
    answer = stoi(EvenNum) + stoi(OddNum);
    
    return answer;
}