#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Index
{
public:
    Index()
        : X(0), Y(0)
    {

    }

    Index(int _X, int _Y)
        : X(_X), Y(_Y)
    {

    }

    bool Compare(const Index& _CompareValue)
    {
        return X == _CompareValue.X && Y == _CompareValue.Y;
    }

    Index operator+(const Index& _PlusValue) const
    {
        return Index(X + _PlusValue.X, Y + _PlusValue.Y);
    }

public:
    int X = 0;
    int Y = 0;
};

bool IsOver(const Index& _CheckIndex, const int MaxX, const int MaxY)
{
    if (0 > _CheckIndex.X)
    {
        return true;
    }
    if (0 > _CheckIndex.Y)
    {
        return true;
    }
    if (MaxX <= _CheckIndex.X)
    {
        return true;
    }
    if (MaxY <= _CheckIndex.Y)
    {
        return true;
    }

    return false;
}

std::vector<int> solution(std::vector<std::string> park, std::vector<std::string> routes)
{
    std::vector<int> answer(2);

    const int ParkRow = static_cast<int>(park.size());
    const int ParkColumn = static_cast<int>(park[0].size());

    Index CurLocation;
    std::vector<std::vector<bool>> Park(ParkRow, std::vector<bool>(ParkColumn, true));

    // MapData
    for (int i = 0; i < ParkRow; ++i)
    {
        std::string RowParkData = park[i];

        for (int j = 0; j < ParkColumn; ++j)
        {
            if ('O' == RowParkData[j])
            {
                continue;
            }
            else if ('X' == RowParkData[j])
            {
                Park[i][j] = false;
            }
            else
            {
                CurLocation = Index(i, j);
            }
        }
    }

    // MoveData
    for (std::string Move : routes)
    {
        std::stringstream ss(Move);
        char MoveDir;
        int MoveCount;

        ss >> MoveDir >> MoveCount;

        bool IsIgnore = false;

        switch (MoveDir)
        {
        case 'E':
        {
            for (int i = 1; i <= MoveCount; ++i)
            {
                Index MoveLocation = CurLocation + Index(0, i);

                if (true == IsOver(MoveLocation, ParkRow, ParkColumn)
                    || false == Park[MoveLocation.X][MoveLocation.Y])
                {
                    IsIgnore = true;
                    break;
                }
                else
                {
                    continue;
                }
            }

            if (false == IsIgnore)
            {
                CurLocation = CurLocation + Index(0, MoveCount);
            }
            break;
        }
        case 'W':
        {
            for (int i = 1; i <= MoveCount; ++i)
            {
                Index MoveLocation = CurLocation + Index(0, -i);

                if (true == IsOver(MoveLocation, ParkRow, ParkColumn)
                    || false == Park[MoveLocation.X][MoveLocation.Y])
                {
                    IsIgnore = true;
                    break;
                }
                else
                {
                    continue;
                }
            }

            if (false == IsIgnore)
            {
                CurLocation = CurLocation + Index(0, -MoveCount);
            }
            break;
        }
        case 'N':
        {
            for (int i = 1; i <= MoveCount; ++i)
            {
                Index MoveLocation = CurLocation + Index(-i, 0);

                if (true == IsOver(MoveLocation, ParkRow, ParkColumn)
                    || false == Park[MoveLocation.X][MoveLocation.Y])
                {
                    IsIgnore = true;
                    break;
                }
                else
                {
                    continue;
                }
            }

            if (false == IsIgnore)
            {
                CurLocation = CurLocation + Index(-MoveCount, 0);
            }
            break;
        }
        case 'S':
        {
            for (int i = 1; i <= MoveCount; ++i)
            {
                Index MoveLocation = CurLocation + Index(i, 0);

                if (true == IsOver(MoveLocation, ParkRow, ParkColumn)
                    || false == Park[MoveLocation.X][MoveLocation.Y])
                {
                    IsIgnore = true;
                    break;
                }
                else
                {
                    continue;
                }
            }

            if (false == IsIgnore)
            {
                CurLocation = CurLocation + Index(MoveCount, 0);
            }
            break;
        }
        default:
            break;
        }
    }

    answer[0] = CurLocation.X;
    answer[1] = CurLocation.Y;

    return answer;
}
