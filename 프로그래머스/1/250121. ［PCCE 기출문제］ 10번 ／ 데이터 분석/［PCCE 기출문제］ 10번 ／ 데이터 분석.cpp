#include <iostream>
#include <string>
#include <vector>
#include <map>

int ReturnIndex(const std::string& _DataName)
{
    if ("code" == _DataName)
    {
        return 0;
    }
    else if ("date" == _DataName)
    {
        return 1;
    }
    else if ("maximum" == _DataName)
    {
        return 2;
    }
    else if ("remain" == _DataName)
    {
        return 3;
    }
}

std::vector<std::vector<int>> solution(std::vector<std::vector<int>> data, std::string ext, int val_ext, std::string sort_by)
{
    std::vector<std::vector<int>> answer;
    const int DataCount = static_cast<int>(data.size());
    answer.reserve(DataCount);

    std::multimap<int, std::vector<int>> answerMap;

    int CompareCondition = ReturnIndex(ext);
    int SortCondition = ReturnIndex(sort_by);

    // 조건에 부합하는 Data 뽑기
    for (std::vector<int> CurData : data)
    {
        if (val_ext > CurData[CompareCondition])
        {
            answerMap.insert(std::make_pair(CurData[SortCondition], CurData));
        }
    }

    // 뽑은 Data 담기
    std::multimap<int, std::vector<int>>::iterator BeginIter = answerMap.begin();
    std::multimap<int, std::vector<int>>::iterator EndIter = answerMap.end();

    for (; BeginIter != EndIter; ++BeginIter)
    {
        answer.push_back(BeginIter->second);
    }

    return answer;
}