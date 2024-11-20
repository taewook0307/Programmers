#include <string>
#include <algorithm>

std::string solution(int n)
{
    std::string answer = "";
    
    while(n > 0)
    {
        int RemainValue = n % 3;
        
        if(0 == RemainValue)
        {
            answer += '4';
            n /= 3;
            --n;
        }
        else
        {
            answer += (RemainValue + '0');
            n /= 3;
        }
    }
    
    std::reverse(answer.begin(), answer.end());
    
    return answer;
}
