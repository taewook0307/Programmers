#include <vector>
#include <set>
#include <algorithm>

std::vector<int> solution(std::vector<int> numbers)
{
    std::vector<int> answer;
    std::set<int> PlusValue;
    
    const size_t NumCount = numbers.size();
    
    for(size_t i = 0; i < NumCount - 1; ++i)
    {
        for(size_t j = i + 1; j < NumCount; ++j)
        {
            PlusValue.insert(numbers[i] + numbers[j]);
        }
    }
    
    answer.reserve(PlusValue.size());
    
    for(int Value : PlusValue)
    {
        answer.push_back(Value);
    }
    
    return answer;
}