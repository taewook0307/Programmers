#include <string>
#include <vector>

int solution(std::string s)
{
    int answer = 0;

    int Length = static_cast<int>(s.size());

    // 초기값
    char x = s[0];
    int Same = 0;       // 문자가 같을 경우의 갯수
    int NotSame = 0;    // 문자가 같지 않을 경우의 갯수

    for (int i = 0; i < Length; ++i)
    {
        // 체크하는 문자가 x와 같을 경우
        if (s[i] == x)
        {
            ++Same;
        }
        // 체크하는 문자가 x와 다를 경우
        else
        {
            ++NotSame;
        }

        // 같은 문자와 같지 않는 문자 수가 서로 같을 경우
        if (Same == NotSame)
        {
            ++answer;
            Same = 0;
            NotSame = 0;
            
            // 오버플로우 방지
            if (Length > i + 1)
            {
                x = s[i + 1];
            }
        }

        // 마지막 문자 체크
        if (i == Length - 1 && Same != NotSame)
        {
            ++answer;
        }
    }

    return answer;
}