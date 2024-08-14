#include <iostream>
#include <vector>
#include <algorithm>

bool Compare(const std::pair<float, int>& _LeftPair, const std::pair<float, int>& _RightPair)
{
    if (_LeftPair.first == _RightPair.first)
    {
        return _LeftPair.second < _RightPair.second;
    }

    return _LeftPair.first > _RightPair.first;
}

std::vector<int> solution(int N, std::vector<int> stages) {
    std::vector<int> answer;
    answer.reserve(N);

    // 실패횟수
    std::vector<int> FailureCount(N);

    for (int StopStage : stages)
    {
        if (N < StopStage)
        {
            continue;
        }

        ++FailureCount[StopStage - 1];
    }

    int UserCount = stages.size();

    std::vector<std::pair<float, int>> FailureRate;
    FailureRate.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        if(UserCount < 0)
        {
            break;
        }
        
        if (UserCount == 0)
        {
            FailureRate.push_back(std::make_pair(0.0f, i + 1));
            continue;
        }

        // 실패율
        float Failure = static_cast<float>(FailureCount[i]) / static_cast<float>(UserCount);

        // 계산된 실패율과 stage 번호 push
        FailureRate.push_back(std::make_pair(Failure, i + 1));

        // 전체 유저 수에서 실패한 인원수 빼기
        UserCount -= FailureCount[i];
    }

    sort(FailureRate.begin(), FailureRate.end(), Compare);

    for (std::pair<float, int> CurIter : FailureRate)
    {
        answer.push_back(CurIter.second);
    }

    return answer;
}