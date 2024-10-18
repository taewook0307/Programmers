#include <string>
#include <vector>
#include <unordered_map>

int solution(std::vector<std::vector<std::string>> clothes)
{
    int answer = 0;

    // 옷의 타입별 인덱스
    std::unordered_map<std::string, int> TypeToIndex;
    // 옷의 타입별 개수
    std::vector<int> TypeToClotheCount(clothes.size(), 0);

    int Index = 0;

    for (const std::vector<std::string>& CurClothe : clothes)
    {
        std::string Type = CurClothe[1];

        if (TypeToIndex.end() != TypeToIndex.find(Type))
        {
            ++TypeToClotheCount[TypeToIndex[Type]];
        }
        else
        {
            TypeToIndex.insert(std::make_pair(Type, Index));
            ++Index;

            ++TypeToClotheCount[TypeToIndex[Type]];
        }
    }
    
    const size_t TypeCount = TypeToIndex.size();

    answer = TypeToClotheCount[0] + 1;

    for (size_t i = 1; i < TypeCount; ++i)
    {
        answer *= (TypeToClotheCount[i] + 1);
    }

    answer -= 1;

    return answer;
}