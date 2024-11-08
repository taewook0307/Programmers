#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<std::vector<int> > land)
{
    int answer = 0;

    std::vector<std::vector<int>> DP(land.size(), std::vector<int>(land[0].size(), 0));

    for (int i = 0; i < 4; ++i)
    {
        DP[0][i] = land[0][i];
    }

    size_t RowCount = land.size();

    for (int i = 1; i < RowCount; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int MaxValue = -1;

            for (int k = 0; k < 4; ++k)
            {
                if (j == k)
                {
                    continue;
                }

                MaxValue = std::max(MaxValue, DP[i - 1][k] + land[i][j]);
            }

            DP[i][j] = MaxValue;
        }
    }

    answer = *std::max_element(DP[RowCount - 1].begin(), DP[RowCount - 1].end());

    return answer;
}