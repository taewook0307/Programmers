#include <unordered_map>
#include <cmath>

void PushMapData(std::unordered_map<int, int>& _Map, int _Value)
{
    if (_Map.end() != _Map.find(_Value))
    {
        ++_Map[_Value];
    }
    else
    {
        _Map.insert(std::make_pair(_Value, 1));
    }
}

int solution(int a, int b, int c, int d)
{
    int Score = 0;

    std::unordered_map<int, int> NumType;

    NumType.insert(std::make_pair(a, 1));

    PushMapData(NumType, b);
    PushMapData(NumType, c);
    PushMapData(NumType, d);

    const int MapSize = static_cast<int>(NumType.size());

    switch (MapSize)
    {
    case 1:
    {
        int DiceNum = NumType.begin()->first;
        Score = 1111 * DiceNum;
        break;
    }
    case 2:
    {
        std::unordered_map<int, int>::iterator FirstIter = NumType.begin();
        int DiceCount = FirstIter->second;

        if (2 == DiceCount)
        {
            int p = FirstIter->first;
            int q = (++FirstIter)->first;

            Score = (p + q) * abs(p - q);
        }
        else
        {
            int p = 3 == FirstIter->second ? FirstIter->first : (++FirstIter)->first;
            std::unordered_map<int, int>::iterator FirstIter = NumType.begin();
            int q = 1 == FirstIter->second ? FirstIter->first : (++FirstIter)->first;
            Score = static_cast<int>(pow(10 * p + q, 2));
        }

        break;
    }
    case 3:
    {
        Score = 1;
        for (const std::pair<int, int>& Pair : NumType)
        {
            if (1 == Pair.second)
            {
                Score *= Pair.first;
            }
        }
        break;
    }
    case 4:
    {
        Score = NumType.begin()->first;
        for (const std::pair<int, int>& Pair : NumType)
        {
            Score = Score < Pair.first ? Score : Pair.first;
        }
        break;
    }
    default:
        break;
    }

    return Score;
}