#include <string>
#include <vector>
#include <cmath>

struct Location
{
    Location(int _X = 0, int _Y = 0)
        : X(_X), Y(_Y)
    {

    }

    int DistanceSqure(const Location& _Other)
    {
        int a = _Other.X - X;
        int b = _Other.Y - Y;

        int DistanceSqure = pow(a, 2) + pow(b, 2);

        return DistanceSqure;
    }

    int X;
    int Y;
};

std::vector<int> solution(int m, int n, int startX, int startY, std::vector<std::vector<int>> balls)
{
    std::vector<int> answer;
    answer.reserve(balls.size());

    Location Start(startX, startY);

    static std::vector<Location> CheckList =
    {
        // 왼쪽
        Location(-Start.X, Start.Y),
        // 오른쪽
        Location(Start.X + 2 *(m - Start.X), Start.Y),
        // 위쪽
        Location(Start.X, Start.Y + 2 * (n - Start.Y)),
        // 아래쪽
        Location(Start.X, -Start.Y)
    };

    for (const std::vector<int>& CurBall : balls)
    {
        Location Destination(CurBall[0], CurBall[1]);

        int MinDistance = -1;

        for (int i = 0; i < 4; ++i)
        {
            Location CheckLocation = CheckList[i];
            int Distance = CheckLocation.DistanceSqure(Destination);

            // X좌표가 같을경우
            if (Destination.X == Start.X)
            {
                // 위쪽
                if (i == 2 && Start.Y < Destination.Y)
                {
                    continue;
                }
                // 아래쪽
                if (i == 3 && Start.Y > Destination.Y)
                {
                    continue;
                }
            }

            // Y좌표가 같을경우
            if (Destination.Y == Start.Y)
            {
                // 왼쪽
                if (i == 0 && Start.X > Destination.X)
                {
                    continue;
                }
                // 오른쪽
                if (i == 1 && Start.X < Destination.X)
                {
                    continue;
                }
            }

            if (MinDistance < 0)
            {
                MinDistance = Distance;
            }
            else
            {
                MinDistance = std::min<int>(MinDistance, Distance);
            }
        }

        answer.push_back(MinDistance);
    }

    return answer;
}