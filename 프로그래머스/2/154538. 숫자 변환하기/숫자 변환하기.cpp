#include <queue>

int solution(int x, int y, int n)
{
    std::queue<std::pair<int, int>> BFS;
    BFS.push(std::make_pair(y, 0));
    
    while(false == BFS.empty())
    {
        int CurNum = BFS.front().first;
        int Count = BFS.front().second;
        
        if(CurNum == x)
        {
            return Count;
        }
        
        BFS.pop();
        
        if(CurNum - n >= x)
        {
            BFS.push(std::make_pair(CurNum - n, Count + 1));
        }
        
        if(CurNum / 2 >= x && CurNum % 2 == 0)
        {
            BFS.push(std::make_pair(CurNum / 2, Count + 1));
        }
        
        if(CurNum / 3 >= x && CurNum % 3 == 0)
        {
            BFS.push(std::make_pair(CurNum / 3, Count + 1));
        }
    }
    
    return -1;
}