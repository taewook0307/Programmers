#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

int solution(std::string begin, std::string target, std::vector<std::string> words)
{
    int answer = 0;
    
    const size_t BeginLen = begin.length();
    const size_t WordCount = words.size();
    
    std::vector<bool> IsChanged(WordCount, false);
    std::unordered_map<std::string, int> ChangeCount;
    
    std::queue<std::string> BFS;
    BFS.push(begin);
    ChangeCount[begin] = 0;
    
    while(false == BFS.empty())
    {
        std::string CurString = BFS.front();
        BFS.pop();
        
        if(CurString == target)
        {
            break;
        }
        
        for(size_t i = 0; i < WordCount; ++i)
        {
            if(true == IsChanged[i])
            {
                continue;
            }
            
            int Count = 0;
            
            for(size_t j = 0; j < BeginLen; ++j)
            {
                if(words[i][j] != CurString[j])
                {
                    ++Count;
                }
            }
            
            if(Count == 1)
            {
                BFS.push(words[i]);
                IsChanged[i] = true;
                ChangeCount[words[i]] = ChangeCount[CurString] + 1;
            }
        }
    }
    
    answer = ChangeCount[target];
    
    return answer;
}