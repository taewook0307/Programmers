#include <vector>
#include <algorithm>

int solution(std::vector<int> people, int limit)
{
    int answer = 0;

    sort(people.begin(), people.end());

    size_t StartIndex = 0;
    size_t LastIndex = people.size() - 1;

    while (StartIndex <= LastIndex)
    {
        if (StartIndex == LastIndex)
        {
            ++answer;
            break;
        }

        int Little = people[StartIndex];
        int Max = people[LastIndex];

        if (Max + Little <= limit)
        {
            ++answer;
            ++StartIndex;
            --LastIndex;
        }
        else
        {
            ++answer;
            --LastIndex;
        }
    }

    return answer;
}