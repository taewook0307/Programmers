#include <string>
#include <vector>
#include <set>

int solution(int m, int n, std::vector<std::string> board)
{
    int answer = 0;

    std::vector<std::vector<char>> CopyBoard(m, std::vector<char>(n, ' '));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            CopyBoard[i][j] = board[i][j];
        }
    }
    
    while(1)
    {
        std::set<std::pair<int, int>> EraseIndex;
        std::vector<std::vector<bool>> BoardState(m, std::vector<bool>(n, false));

        for (int i = 0; i < m - 1; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                if (CopyBoard[i][j] == '.')
                {
                    continue;
                }

                if (CopyBoard[i][j] == CopyBoard[i + 1][j]
                    && CopyBoard[i][j] == CopyBoard[i][j + 1]
                    && CopyBoard[i][j] == CopyBoard[i + 1][j + 1])
                {
                    EraseIndex.insert(std::make_pair(i, j));
                    EraseIndex.insert(std::make_pair(i + 1, j));
                    EraseIndex.insert(std::make_pair(i, j + 1));
                    EraseIndex.insert(std::make_pair(i + 1, j + 1));

                    BoardState[i][j] = true;
                    BoardState[i + 1][j] = true;
                    BoardState[i][j + 1] = true;
                    BoardState[i + 1][j + 1] = true;
                }
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (BoardState[i][j] == true)
                {
                    CopyBoard[i][j] = '.';
                }
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0)
                {
                    continue;
                }

                if (CopyBoard[i][j] == '.')
                {
                    int StartX = i;

                    while (StartX > -1)
                    {
                        int CheckX = StartX - 1;

                        if (CheckX < 0)
                        {
                            break;
                        }

                        if (CopyBoard[CheckX][j] == '.')
                        {
                            break;
                        }

                        std::swap(CopyBoard[StartX][j], CopyBoard[CheckX][j]);
                        --StartX;
                    }
                }
            }
        }

        if (EraseIndex.size() == 0)
        {
            break;
        }

        answer += EraseIndex.size();
    }

    return answer;
}