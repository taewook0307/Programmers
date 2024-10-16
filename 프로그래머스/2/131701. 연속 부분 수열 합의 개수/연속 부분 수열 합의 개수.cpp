#include <vector>
#include <set>

int solution(std::vector<int> elements)
{
    int answer = 0;

    std::vector<int> IncreaseVector;
    IncreaseVector.reserve(elements.size() * 2);
    
    for (int i = 0; i < 2; ++i)
    {
        for (int CurElement : elements)
        {
            IncreaseVector.emplace_back(CurElement);
        }
    }

    std::set<int> AllCombi;

    const size_t ElementCount = elements.size();

    for (size_t i = 0; i < ElementCount; ++i)
    {
        std::vector<int> Combination(ElementCount, elements[i]);

        int Index = 1;

        for (size_t j = i + 1; j < ElementCount + i; ++j)
        {
            for (size_t k = Index; k < ElementCount; ++k)
            {
                Combination[k] += IncreaseVector[j];
            }

            ++Index;
        }
        
        for (int CombiSum : Combination)
        {
            AllCombi.insert(CombiSum);
        }
    }

    answer = AllCombi.size();

    return answer;
}