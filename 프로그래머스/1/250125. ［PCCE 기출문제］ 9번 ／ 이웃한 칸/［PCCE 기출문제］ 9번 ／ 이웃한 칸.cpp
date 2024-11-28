#include <string>
#include <vector>
#include <array>

int solution(std::vector<std::vector<std::string>> board, int h, int w)
{
    int answer = 0;
    
    const size_t Row = board.size();
    const size_t Column = board[0].size();
    
    std::array<int, 4> DirX = {-1, 1, 0, 0};
    std::array<int, 4> DirY = {0, 0, -1, 1};
    
    for(int i = 0; i < 4; ++i)
    {
        int CheckX = h + DirX[i];
        int CheckY = w + DirY[i];
        
        if(CheckX < 0 || CheckY < 0 || CheckX >= Row || CheckY >= Column)
        {
            continue;
        }
        
        if(board[h][w] == board[CheckX][CheckY])
        {
            ++answer;
        }
    }
    
    return answer;
}