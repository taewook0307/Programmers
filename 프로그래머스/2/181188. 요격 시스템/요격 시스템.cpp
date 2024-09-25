#include <string>
#include <vector>
#include <algorithm>

struct Width
{
    Width(int _Left = 0, int _Right = 0)
        : Left(_Left), Right(_Right)
    {

    }

    int GetLength() const
    {
        return Right - Left;
    }

    int Left = -1;
    int Right = -1;
};

bool IsOverlap(const Width& _X, const Width& _Y)
{
    if (_X.Left >= _Y.Right || _X.Right <= _Y.Left)
    {
        return false;
    }

    return true;
}

bool Compare(const std::vector<int>& _Left, const std::vector<int>& _Right)
{
    if (_Left[0] == _Right[0])
    {
        return _Left[1] > _Right[1];
    }

    return _Left[0] > _Right[0];
}

int solution(std::vector<std::vector<int>> targets)
{
    int answer = 1;

    sort(targets.begin(), targets.end(), Compare);
    int MissileCount = static_cast<int>(targets.size());

    Width CheckMissile = Width(targets[0][0], targets[0][1]);

    for (int i = 1; i < MissileCount; ++i)
    {
        Width CurMissile = Width(targets[i][0], targets[i][1]);

        if (true == IsOverlap(CheckMissile, CurMissile))
        {
            CheckMissile = CheckMissile.Left > CurMissile.Left ? CheckMissile : CurMissile;
        }
        else
        {
            CheckMissile = CurMissile;
            ++answer;
        }
    }

    return answer;
}