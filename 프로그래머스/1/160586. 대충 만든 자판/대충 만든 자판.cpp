#include <string>
#include <vector>
#include <climits>
#include <algorithm>

std::vector<int> solution(std::vector<std::string> keymap, std::vector<std::string> targets)
{
    std::vector<int> answer;
    answer.reserve(targets.size());

    for (const std::string& Target : targets)
    {
        int Count = 0;

        for (char CurChar : Target)
        {
            int PressCount = INT_MAX;

            for (const std::string& CurMap : keymap)
            {
                std::string::const_iterator FindIter = std::find(CurMap.begin(), CurMap.end(), CurChar);

                if (FindIter == CurMap.end())
                {
                    if (PressCount == INT_MAX)
                    {
                        PressCount = -1;
                    }
                }
                else
                {
                    int Index = FindIter - CurMap.begin();

                    if (PressCount == -1)
                    {
                        PressCount = Index + 1;
                    }
                    else
                    {
                        PressCount = std::min(PressCount, Index + 1);
                    }
                }
            }

            if (PressCount != -1)
            {
                Count += PressCount;
            }
            else
            {
                Count = -1;
                break;
            }
        }

        answer.push_back(Count);
    }

    return answer;
}