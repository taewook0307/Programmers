#include <string>
#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> answers)
{
    std::vector<int> answer;
    
    std::vector<std::vector<int>> People = {{1, 2, 3, 4, 5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5}};
    std::vector<int> Score(3, 0);
    
    const size_t AnswerCount = answers.size();
    
    int Person0Index = 0;
    int Person1Index = 0;
    int Person2Index = 0;
    
    for(int i = 0; i < AnswerCount; ++i)
    {
        if(answers[i] == People[0][Person0Index])
        {
            ++Score[0];
        }
        
        if(answers[i] == People[1][Person1Index])
        {
            ++Score[1];
        }
        
        if(answers[i] == People[2][Person2Index])
        {
            ++Score[2];
        }
        
        ++Person0Index;
        ++Person1Index;
        ++Person2Index;
        
        if(Person0Index == 5)
        {
            Person0Index = 0;
        }
        
        if(Person1Index == 8)
        {
            Person1Index = 0;
        }
        
        if(Person2Index == 10)
        {
            Person2Index = 0;
        }
    }
    
    int MaxScore = *std::max_element(Score.begin(), Score.end());
    
    for(int i = 0; i < 3; ++i)
    {
        if(Score[i] == MaxScore)
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}