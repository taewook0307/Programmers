#include <string>
#include <vector>
#include <algorithm>

static int CompareIndex = 0;

bool Compare(const std::string& _Left, const std::string& _Right)
{
    if (_Left[CompareIndex] == _Right[CompareIndex])
    {
        return _Left < _Right;
    }

    return _Left[CompareIndex] < _Right[CompareIndex];
}

std::vector<std::string> solution(std::vector<std::string> strings, int n)
{
    CompareIndex = n;

    sort(strings.begin(), strings.end(), Compare);

    return strings;
}