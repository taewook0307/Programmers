#include <string>
#include <array>
#include <vector>
#include <queue>

struct Index
{
    Index(int _X = 0, int _Y = 0)
        : X(_X), Y(_Y)
    {

    }

    Index(const Index& _Other)
        : X(_Other.X), Y(_Other.Y)
    {

    }

    bool operator==(const Index& _Other)
    {
        return this->X == _Other.X && this->Y == _Other.Y;
    }

    bool operator!=(const Index& _Other)
    {
        return this->X != _Other.X || this->Y != _Other.Y;
    }

    int X;
    int Y;
};

bool IsOver(int _X, int _Y, int _Row, int _Column)
{
    if (_X < 0)
    {
        return true;
    }
    if (_Y < 0)
    {
        return true;
    }
    if (_X >= _Row)
    {
        return true;
    }
    if (_Y >= _Column)
    {
        return true;
    }

    return false;
}

int solution(std::vector<std::string> board)
{
    int RowCount = static_cast<int>(board.size());
    int ColumnCount = static_cast<int>(board[0].size());

    std::vector<std::vector<bool>> IsVisit(RowCount, std::vector<bool>(ColumnCount, false));
    std::vector<std::vector<int>> Distance(RowCount, std::vector<int>(ColumnCount, 0));

    Index CurLocation;
    Index Destination;

    // 초기값 세팅
    for (int i = 0; i < RowCount; ++i)
    {
        for (int j = 0; j < ColumnCount; ++j)
        {
            Index CurIndex(i, j);

            // 장애물
            if ('D' == board[i][j])
            {
                Distance[i][j] = -1;
            }
            // 시작점
            else if ('R' == board[i][j])
            {
                CurLocation.X = i;
                CurLocation.Y = j;
                IsVisit[CurLocation.X][CurLocation.Y] = true;
            }
            // 도착점
            else if ('G' == board[i][j])
            {
                Destination.X = i;
                Destination.Y = j;
            }
            // 그 외
            else
            {
                continue;
            }
        }
    }

    // 시작점 Queue에 세팅
    std::queue<Index> Search;
    Search.push(CurLocation);

    // 탐색 시작
    while (true != Search.empty())
    {
        CurLocation.X = Search.front().X;
        CurLocation.Y = Search.front().Y;

        if (CurLocation == Destination)
        {
            return Distance[Destination.X][Destination.Y];
        }

        Search.pop();
        
        std::array<int, 4> PlusX = { -1, 1, 0, 0 };
        std::array<int, 4> PlusY = { 0, 0, -1, 1 };

        Index MoveIndex(CurLocation);

        for (int i = 0; i < 4; ++i)
        {
            
            MoveIndex.X = CurLocation.X + PlusX[i];
            MoveIndex.Y = CurLocation.Y + PlusY[i];

            while (false == IsOver(MoveIndex.X, MoveIndex.Y, RowCount, ColumnCount))
            {
                if ('D' == board[MoveIndex.X][MoveIndex.Y])
                {
                    break;
                }

                MoveIndex.X += PlusX[i];
                MoveIndex.Y += PlusY[i];
            }

            MoveIndex.X -= PlusX[i];
            MoveIndex.Y -= PlusY[i];

            if (MoveIndex != CurLocation && false == IsVisit[MoveIndex.X][MoveIndex.Y])
            {
                Search.push(MoveIndex);
                Distance[MoveIndex.X][MoveIndex.Y] = Distance[CurLocation.X][CurLocation.Y] + 1;
                IsVisit[MoveIndex.X][MoveIndex.Y] = true;
            }
        }
    }

    // 도착하지 못했을 경우
    if (false == IsVisit[Destination.X][Destination.Y])
    {
        return -1;
    }
}