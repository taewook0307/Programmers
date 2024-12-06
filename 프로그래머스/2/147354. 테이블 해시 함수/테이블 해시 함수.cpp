#include <vector>
#include <algorithm>

int solution(std::vector<std::vector<int>> data, int col, int row_begin, int row_end)
{
    int answer = -1;

    std::sort(data.begin(), data.end(),
        [col](const std::vector<int>& _Left, const std::vector<int>& _Right)
        {
            if (_Left[col - 1] == _Right[col - 1])
            {
                return _Left[0] > _Right[0];
            }

            return _Left[col - 1] < _Right[col - 1];
        }
    );

    for (int i = row_begin - 1; i < row_end; ++i)
    {
        int S_i = 0;

        const std::vector<int>& Tuple = data[i];
        const size_t DataCount = Tuple.size();

        for (size_t j = 0; j < DataCount; ++j)
        {
            S_i += Tuple[j] % (i + 1);
        }

        if (answer == -1)
        {
            answer = S_i;
        }
        else
        {
            answer = answer ^ S_i;
        }
    }

    return answer;
}