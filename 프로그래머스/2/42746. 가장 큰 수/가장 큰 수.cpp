#include <string>
#include <vector>
#include <algorithm>

bool Compare(const std::string& _Left, const std::string& _Right)
{
    return _Left + _Right > _Right + _Left;
}

std::string solution(std::vector<int> numbers)
{
    std::string answer = "";

    std::vector<std::string> StringNumbers;

    for (int Num : numbers)
    {
        std::string StringNum = std::to_string(Num);
        StringNumbers.push_back(StringNum);
    }

    std::sort(StringNumbers.begin(), StringNumbers.end(), Compare);

    if(StringNumbers[0] == "0")
    {
        return "0";
    }
    
    for (const std::string& Num : StringNumbers)
    {
        answer += Num;
    }

    return answer;
}