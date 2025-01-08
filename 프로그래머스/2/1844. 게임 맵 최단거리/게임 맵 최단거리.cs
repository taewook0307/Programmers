using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    public int solution(int[,] maps)
    {
        int answer = 0;

        int Row = maps.GetLength(0);
        int Column = maps.GetLength(1);

        int[] DirX = { -1, 1, 0, 0 };
        int[] DirY = { 0, 0, - 1, 1 };

        List<List<int>> Pay = new List<List<int>>();

        for (int i = 0; i < Row; i++)
        {
            Pay.Add(new List<int>(new int[Column]));
        }

        List<List<bool>> IsVisited = new List<List<bool>>();

        for (int i = 0; i < Row; i++)
        {
            IsVisited.Add(new List<bool>(new bool[Column]));
        }

        Queue<KeyValuePair<int, int>> BFS = new Queue<KeyValuePair<int, int>>();

        BFS.Enqueue(new KeyValuePair<int, int>(0, 0));
        Pay[0][0] = 1;
        IsVisited[0][0] = true;

        while (true == BFS.Any())
        {
            KeyValuePair<int, int> CurNode = BFS.Dequeue();

            for(int i = 0; i < 4; ++i)
            {
                int NewX = CurNode.Key + DirX[i];
                int NewY = CurNode.Value + DirY[i];

                if(NewX < 0
                   || NewY < 0
                   || NewX == Row
                   || NewY == Column
                   || IsVisited[NewX][NewY] == true
                   || maps[NewX, NewY] == 0)
                {
                    continue;
                }

                IsVisited[NewX][NewY] = true;
                Pay[NewX][NewY] = Pay[CurNode.Key][CurNode.Value] + 1;
                BFS.Enqueue(new KeyValuePair<int, int>(NewX, NewY));
            }
        }

        if(true == IsVisited[Row - 1][Column - 1])
        {
            answer = Pay[Row - 1][Column - 1];
        }
        else
        {
            answer = -1;
        }

        return answer;
    }
}