#include <iostream>
#include <string>
#include <vector>
#include <map>

std::vector<int> solution(int N, std::vector<int> stages) {
    std::vector<int> answer(N);

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
    // 실패율과 스테이지 번호 저장용 multimap
    std::multimap<float, int, std::greater<>> FailureRate;

    for (int i = 0; i < N; ++i)
    {
        if (UserCount < 0)
        {
            break;
        }

        // 실패율
        float Failure = static_cast<float>(FailureCount[i]) / static_cast<float>(UserCount);
        // 계산된 실패율과 stage 번호 insert
        FailureRate.insert(std::make_pair(Failure, i + 1));
        // 전체 유저 수에서 실패한 횟수 빼기
        UserCount -= FailureCount[i];
    }

    int i = 0;

    for (std::pair<float, int> CurIter : FailureRate)
    {
        answer[i] = CurIter.second;
        ++i;
    }

    return answer;
}