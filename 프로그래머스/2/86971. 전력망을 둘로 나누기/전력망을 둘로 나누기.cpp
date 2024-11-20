#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

int solution(int n, std::vector<std::vector<int>> wires)
{
    int answer = INT_MAX;

    std::sort(wires.begin(), wires.end());

    const size_t Count = wires.size();
    size_t RemoveIndex = 0;

    while (RemoveIndex != Count)
    {
        std::vector<std::vector<int>> CheckWires;
        CheckWires.reserve(Count - 1);

        for (int i = 0; i < Count; ++i)
        {
            if (i == RemoveIndex)
            {
                continue;
            }

            CheckWires.push_back(wires[i]);
        }

        std::vector<bool> IsVisit(n + 1, false);
        std::queue<int> Node;

        IsVisit[CheckWires[0][0]] = true;
        Node.push(CheckWires[0][0]);

        while (false == Node.empty())
        {
            int Begin = Node.front();
            Node.pop();

            for (const std::vector<int>& CurNode : CheckWires)
            {
                int CurNodeBegin = CurNode[0];
                int CurNodeEnd = CurNode[1];

                if (CurNodeBegin > Begin)
                {
                    break;
                }

                if (CurNodeBegin == Begin && false == IsVisit[CurNodeEnd])
                {
                    Node.push(CurNodeEnd);
                    IsVisit[CurNodeEnd] = true;
                }

                if (CurNodeEnd == Begin && false == IsVisit[CurNodeBegin])
                {
                    Node.push(CurNodeBegin);
                    IsVisit[CurNodeBegin] = true;
                }
            }
        }

        int NetOneCount = 0;
        int NetTwoCount = 0;

        for (int i = 1; i < n + 1; ++i)
        {
            if (IsVisit[i] == true)
            {
                ++NetOneCount;
            }
            else
            {
                ++NetTwoCount;
            }
        }

        int Difference = abs(NetOneCount - NetTwoCount);

        answer = std::min(Difference, answer);

        ++RemoveIndex;
    }

    return answer;
}