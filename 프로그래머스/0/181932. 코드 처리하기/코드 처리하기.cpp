#include <string>
#include <vector>

std::string solution(std::string code)
{
    std::string answer = "";

    bool Mode = false;

    const int CodeSize = static_cast<int>(code.size());

    for (int i = 0; i < CodeSize; ++i)
    {
        char CurChar = code[i];

        if ('1' == CurChar)
        {
            Mode = !Mode;
            continue;
        }

        if (true == Mode && 1 == i % 2)
        {
            answer += CurChar;
        }
        else if(false == Mode && 0 == i % 2)
        {
            answer += CurChar;
        }
    }
    
    if ("" == answer)
    {
        answer = "EMPTY";
    }

    return answer;
}