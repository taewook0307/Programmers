#include <vector>
#include <queue>

int solution(std::vector<int> queue1, std::vector<int> queue2)
{
    int answer = 0;
    int MaxValue = static_cast<int>(queue1.size()) * 4;
    
    std::queue<int> QueueOne;
    std::queue<int> QueueTwo;
    
    long Queue1Sum = 0;
    long Queue2Sum = 0;
    
    for(int Num : queue1)
    {
        QueueOne.push(Num);
        Queue1Sum += static_cast<long>(Num);
    }
    
    for(int Num : queue2)
    {
        QueueTwo.push(Num);
        Queue2Sum += static_cast<long>(Num);
    }
    
    if((Queue1Sum + Queue2Sum) % 2 != 0)
    {
        return -1;
    }
    
    while(false == QueueOne.empty() && false == QueueTwo.empty())
    {
        if(answer > MaxValue)
        {
            return -1;
        }
        
        if(Queue1Sum > Queue2Sum)
        {
            int PopValue = QueueOne.front();
            QueueOne.pop();
            QueueTwo.push(PopValue);
            answer += 1;
            Queue1Sum -= PopValue;
            Queue2Sum += PopValue;
        }
        else if(Queue1Sum < Queue2Sum)
        {
            int PopValue = QueueTwo.front();
            QueueTwo.pop();
            QueueOne.push(PopValue);
            answer += 1;
            Queue1Sum += PopValue;
            Queue2Sum -= PopValue;
        }
        else
        {
            break;
        }
    }
    
    if(true == QueueOne.empty() || true == QueueTwo.empty())
    {
        return -1;
    }
    
    return answer;
}