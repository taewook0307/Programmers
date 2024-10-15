#include <string>
#include <vector>
#include <algorithm>

bool Compare(const std::vector<int>& _Left, const std::vector<int>& _Right)
{
    if (_Left[1] == _Right[1] && _Left[0] == _Right[0])
    {
        return _Left[2] > _Right[2];
    }

    if (_Left[0] == _Right[0])
    {
        return _Left[1] > _Right[1];
    }

    return _Left[0] > _Right[0];
}

int solution(std::vector<int> picks, std::vector<std::string> minerals)
{
    int answer = 0;

    int DiaPick = picks[0];
    int IronPick = picks[1];
    int StonePick = picks[2];

    // 가지고 있는 곡갱이로 캘 수 있는 갯수
    int PossibleCount = (DiaPick + IronPick + StonePick) * 5;

    // 광물 갯수
    const size_t MineralCount = minerals.size();

    // 캘 수 있는 실제 갯수
    const size_t DigCount = MineralCount > PossibleCount ? PossibleCount : MineralCount;

    // 한 곡갱이로 캐야 하는 광물 종류 별 갯수
    std::vector<std::vector<int>> CountToType;

    // (다이아 갯수, 철 갯수, 돌 갯수)
    std::vector<int> PushVector(3, 0);

    // CountToType 구해서 Push
    for (size_t i = 0; i < DigCount; i++)
    {
        if (minerals[i] == "diamond")
        {
            ++PushVector[0];
        }
        else if (minerals[i] == "iron")
        {
            ++PushVector[1];
        }
        else
        {
            ++PushVector[2];
        }


        if (i % 5 == 4 || i == DigCount - 1)
        {
            CountToType.push_back(PushVector);
            PushVector[0] = 0;
            PushVector[1] = 0;
            PushVector[2] = 0;
        }
    }

    // 배열의 원소 갯수가 큰 순서대로 정렬
    sort(CountToType.begin(), CountToType.end(), Compare);

    for (const std::vector<int>& CurMinerals : CountToType)
    {
        // 가지고 있는 곡갱이를 대상으로 피로도 계산 후 answer +
        if (DiaPick > 0)
        {
            int Fatigue = CurMinerals[0] + CurMinerals[1] + CurMinerals[2];
            answer += Fatigue;

            --DiaPick;
            continue;
        }

        if (IronPick > 0)
        {
            int Fatigue = (CurMinerals[0] * 5) + CurMinerals[1] + CurMinerals[2];
            answer += Fatigue;

            --IronPick;
            continue;
        }

        if (StonePick > 0)
        {
            int Fatigue = (CurMinerals[0] * 25) + (CurMinerals[1] * 5) + CurMinerals[2];
            answer += Fatigue;

            --StonePick;
            continue;
        }
    }

    return answer;
}