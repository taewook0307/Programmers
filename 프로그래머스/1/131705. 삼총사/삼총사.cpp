#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;

    const int StudentCount = number.size();

    for (int i = 2; i < StudentCount; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            for (int k = 0; k < j; ++k)
            {
                int SumValue = number[i] + number[j] + number[k];

                if (0 == SumValue)
                {
                    ++answer;
                }
            }
        }
    }

    return answer;
}