#include <string>
#include <vector>

int solution(std::vector<int> absolutes, std::vector<bool> signs)
{
    int answer = 0;

    const int VectorSize = static_cast<int>(absolutes.size());

    for (int i = 0; i < VectorSize; ++i)
    {
        int Value = true == signs[i] ? absolutes[i] : -absolutes[i];

        answer += Value;
    }

    return answer;
}