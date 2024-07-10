#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    std::vector<int> answer;

    const int scoreSize = score.size();
    answer.reserve(scoreSize);

    std::vector<int> GloryValue;
    GloryValue.reserve(k);

    for (int i = 0; i < scoreSize; ++i)
    {
        int Size = GloryValue.size();

        if (k > Size)
        {
            GloryValue.push_back(score[i]);
            
            sort(GloryValue.begin(), GloryValue.end());
        }
        else
        {
            int CurValue = score[i];

            if (GloryValue[0] > CurValue)
            {
                answer.push_back(GloryValue[0]);
                continue;
            }

            GloryValue[0] = CurValue;

            sort(GloryValue.begin(), GloryValue.end());
        }

        answer.push_back(GloryValue[0]);
    }

    return answer;
}