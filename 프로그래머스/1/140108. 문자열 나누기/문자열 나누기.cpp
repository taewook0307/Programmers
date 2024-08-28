#include <string>
#include <vector>

int solution(std::string s)
{
    int answer = 0;

    int Length = static_cast<int>(s.size());

    char x = s[0];
    int Same = 0;
    int NotSame = 0;

    for (int i = 0; i < Length; ++i)
    {
        if (s[i] == x)
        {
            ++Same;
        }
        else
        {
            ++NotSame;
        }

        if (Same == NotSame)
        {
            ++answer;
            Same = 0;
            NotSame = 0;
            
            if (Length > i + 1)
            {
                x = s[i + 1];
            }
        }

        if (i == Length - 1 && Same != NotSame)
        {
            ++answer;
        }
    }

    return answer;
}