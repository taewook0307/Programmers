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

int solution(std::vector<std::vector<int>> targets)
{
    sort(targets.begin(), targets.end());
    int MissileCount = static_cast<int>(targets.size());

    std::vector<Width> InterceptCount;

    for (int i = 0; i < MissileCount; ++i)
    {
        Width CurMissile = Width(targets[i][0], targets[i][1]);
        bool IsIntercept = false;

        const int InterceptSize = static_cast<int>(InterceptCount.size());

        for (int i = 0; i < InterceptSize; ++i)
        {
            if (true == IsOverlap(InterceptCount[i], CurMissile))
            {
                InterceptCount[i] = InterceptCount[i].Right < CurMissile.Right ? InterceptCount[i] : CurMissile;
                IsIntercept = true;
            }
        }

        if (false == IsIntercept)
        {
            InterceptCount.push_back(CurMissile);
        }
    }

    return InterceptCount.size();
}