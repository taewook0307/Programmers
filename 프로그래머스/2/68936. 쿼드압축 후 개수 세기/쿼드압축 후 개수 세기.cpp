#include <string>
#include <vector>

bool IsSame(const std::vector<std::vector<int>>& _CheckVector, int _StartX, int _EndX, int _StartY, int _EndY)
{
    int Check = _CheckVector[_StartX][_StartY];

    for (int i = _StartX; i < _EndX; ++i)
    {
        for (int j = _StartY; j < _EndY; ++j)
        {
            if (Check != _CheckVector[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

void SetCheckTrue(std::vector<std::vector<bool>>& _ChangeVector, int _StartX, int _EndX, int _StartY, int _EndY)
{
    for (int i = _StartX; i < _EndX; ++i)
    {
        for (int j = _StartY; j < _EndY; ++j)
        {
            _ChangeVector[i][j] = true;
        }
    }
}

std::vector<int> solution(std::vector<std::vector<int>> arr)
{
    std::vector<int> answer(2, 0);

    size_t Row = arr.size();
    size_t Column = arr[0].size();

    size_t CheckRange = Row;

    std::vector<std::vector<bool>> IsCompression(Row, std::vector<bool>(Column, false));

    while (CheckRange != 0)
    {
        for (int i = 0; i < Row; i += CheckRange)
        {
            for (int j = 0; j < Column; j += CheckRange)
            {
                if (IsCompression[i][j] == true)
                {
                    continue;
                }

                if (true == IsSame(arr, i, i + CheckRange, j, j + CheckRange))
                {
                    SetCheckTrue(IsCompression, i, i + CheckRange, j, j + CheckRange);
                    if (arr[i][j] == 0)
                    {
                        ++answer[0];
                    }
                    else
                    {
                        ++answer[1];
                    }
                }
            }
        }

        CheckRange /= 2;
    }

    return answer;
}