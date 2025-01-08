using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    public int solution(int[,] maps)
    {
        int Row = maps.GetLength(0);
        int Column = maps.GetLength(1);

        int[] DirX = { -1, 1, 0, 0 };
        int[] DirY = { 0, 0, -1, 1 };

        int[,] Pay = new int[Row, Column];
        bool[,] IsVisited = new bool[Row, Column];

        Queue<(int, int)> BFS = new Queue<(int, int)>();

        BFS.Enqueue((0, 0));
        Pay[0, 0] = 1;
        IsVisited[0, 0] = true;

        while (BFS.Count > 0)
        {
            var (curX, curY) = BFS.Dequeue();

            if (curX == Row - 1 && curY == Column - 1)
            {
                return Pay[curX, curY];
            }

            for (int i = 0; i < 4; ++i)
            {
                int NewX = curX + DirX[i];
                int NewY = curY + DirY[i];

                if (NewX < 0 || NewY < 0 || NewX == Row || NewY == Column 
                    || IsVisited[NewX, NewY] || maps[NewX, NewY] == 0)
                {
                    continue;
                }

                IsVisited[NewX, NewY] = true;
                Pay[NewX, NewY] = Pay[curX, curY] + 1;
                BFS.Enqueue((NewX, NewY));
            }
        }

        return -1;
    }
}