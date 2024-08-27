#include <string>
#include <vector>

int solution(int n, std::vector<int> lost, std::vector<int> reserve)
{
    int answer = 0;

    std::vector<int> Clothes(n, 1);

    // 잃어버린 학생들 체육복 수 계산
    for (const int LostStudent : lost)
    {
        --Clothes[LostStudent - 1];
    }

    // 여분을 가진 학생들 체육복 수 계산
    for (const int ReserveStudent : reserve)
    {
        ++Clothes[ReserveStudent - 1];
    }

    // 전체 학생 중 체육복이 없는 이 확인
    for (int i = 0; i < n; ++i)
    {
        if (0 == Clothes[i])
        {
            int PrevNum = i - 1;
            int BackNum = i + 1;

            if (PrevNum >= 0)
            {
                if (2 == Clothes[PrevNum])
                {
                    Clothes[PrevNum] = 1;
                    Clothes[i] = 1;
                }
            }

            if (n > BackNum)
            {
                if (2 == Clothes[BackNum] && 0 == Clothes[i])
                {
                    Clothes[BackNum] = 1;
                    Clothes[i] = 1;
                }
            }
        }
    }

    for (const int Result : Clothes)
    {
        if (0 < Result)
        {
            ++answer;
        }
    }

    return answer;
}