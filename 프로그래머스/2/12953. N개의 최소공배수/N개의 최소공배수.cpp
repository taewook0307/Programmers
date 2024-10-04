#include <vector>
#include <algorithm>

int solution(std::vector<int> arr)
{
    int answer = 0;

    // 오름차순으로 정렬
    sort(arr.begin(), arr.end());

    const size_t NumCount = arr.size();

    // 가장 큰 값
    int LargeValue = arr[NumCount - 1];
    int CurrentMultiple = 1;

    while (true)
    {
        // 1부터 차례대로 가장 큰 수에 곱을 구함
        int Check = CurrentMultiple * LargeValue;
        
        bool AllClear = true;

        for (int i = 0; i < NumCount; ++i)
        {
            if (0 != Check % arr[i])
            {
                AllClear = false;
                break;
            }
        }

        // arr의 모든 수로 곱한 수가 나누어질 경우 정답
        if (true == AllClear)
        {
            answer = Check;
            break;
        }

        ++CurrentMultiple;
    }

    return answer;
}