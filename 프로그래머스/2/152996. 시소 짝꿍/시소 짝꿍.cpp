#include <vector>
#include <algorithm>

long long solution(std::vector<int> weights)
{
    long long answer = 0;

    sort(weights.begin(), weights.end());

    const size_t People = weights.size();

    for (size_t i = 0; i < People; ++i)
    {
        for (size_t j = i + 1; j < People; ++j)
        {
            if (weights[i] == weights[j])
            {
                ++answer;
                continue;
            }

            int HeavyPerson = weights[i] < weights[j] ? weights[j] : weights[i];
            int LightPerson = weights[i] < weights[j] ? weights[i] : weights[j];

            if (HeavyPerson * 2 == LightPerson * 3
                || HeavyPerson * 2 == LightPerson * 4
                || HeavyPerson * 3 == LightPerson * 4)
            {
                ++answer;
            }
        }
    }

    return answer;
}