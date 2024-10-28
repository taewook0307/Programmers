#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

int solution(int k, std::vector<std::vector<int>> dungeons)
{
    int answer = 0;

    std::map<int, std::pair<int, int>> DungeonMap;
    int Number = 1;
    for (const std::vector<int>& CurDungeon : dungeons)
    {
        DungeonMap.insert(std::make_pair(Number, std::make_pair(CurDungeon[0], CurDungeon[1])));
        ++Number;
    }

    size_t DuegeonCount = dungeons.size();

    std::vector<int> CurSeq(DuegeonCount);
    std::iota(CurSeq.begin(), CurSeq.end(), 1);
    do
    {
        int Count = 0;
        int Energy = k;

        for (size_t j = 0; j < DuegeonCount; ++j)
        {
            std::pair<int, int> Dungeon = DungeonMap[CurSeq[j]];

            if (Energy < Dungeon.first)
            {
                continue;
            }

            if (Energy < Dungeon.second)
            {
                continue;
            }

            Energy -= Dungeon.second;
            ++Count;
        }

        answer = std::max(answer, Count);

    } while (true == std::next_permutation(CurSeq.begin(), CurSeq.end()));

    return answer;
}