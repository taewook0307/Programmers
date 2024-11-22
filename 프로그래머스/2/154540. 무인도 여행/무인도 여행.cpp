#include <string>
#include <vector>
#include <array>
#include <stack>
#include <algorithm>

std::vector<int> solution(std::vector<std::string> maps)
{
    std::vector<int> answer;

    const size_t Row = maps.size();
    const size_t Column = maps[0].length();

    std::array<int, 4> DirX = {-1, 1, 0, 0};
    std::array<int, 4> DirY = {0, 0, -1, 1};

    std::vector<std::vector<bool>> Check(Row, std::vector<bool>(Column, false));

    for (size_t i = 0; i < Row; ++i)
    {
        for (size_t j = 0; j < Column; ++j)
        {
            if ('X' == maps[i][j])
            {
                Check[i][j] = true;
            }
        }
    }

    for (size_t i = 0; i < Row; ++i)
    {
        for (size_t j = 0; j < Column; ++j)
        {
            if (true == Check[i][j])
            {
                continue;
            }

            std::pair<int, int> Start = std::make_pair(i, j);

            std::vector<std::vector<bool>> IsVisited(Row, std::vector<bool>(Column, false));
            std::stack<std::pair<int, int>> Node;
            Node.push(Start);
            IsVisited[Start.first][Start.second] = true;
            int Day = 0;

            while (false == Node.empty())
            {
                std::pair<int, int> CurNode = Node.top();

                bool Flag = false;

                for (int i = 0; i < 4; ++i)
                {
                    int NewX = CurNode.first + DirX[i];
                    int NewY = CurNode.second + DirY[i];

                    if (NewX < 0 || NewY < 0 || NewX >= Row || NewY >= Column)
                    {
                        continue;
                    }

                    if (false == IsVisited[NewX][NewY] && 'X' != maps[NewX][NewY])
                    {
                        Node.push(std::make_pair(NewX, NewY));
                        IsVisited[NewX][NewY] = true;
                        Flag = true;
                        break;
                    }
                }

                if (Flag == false)
                {
                    Node.pop();
                    Day += maps[CurNode.first][CurNode.second] - '0';
                    Check[CurNode.first][CurNode.second] = true;

                    if (CurNode == Start)
                    {
                        answer.push_back(Day);
                    }
                }
            }
        }
    }

    if (true == answer.empty())
    {
        answer.push_back(-1);
    }
    else
    {
        std::sort(answer.begin(), answer.end());
    }

    return answer;
}