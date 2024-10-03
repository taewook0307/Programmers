#include <iostream>
#include <string>
#include <stack>

int solution(std::string s)
{
    int answer = -1;

    std::stack<char> SStack;

    for (char CurChar : s)
    {
        if (true == SStack.empty())
        {
            SStack.push(CurChar);
        }
        else
        {
            char TopChar = SStack.top();

            if (TopChar == CurChar)
            {
                SStack.pop();
            }
            else
            {
                SStack.push(CurChar);
            }
        }
    }

    answer = SStack.empty() == true ? 1 : 0;

    std::cout << answer << std::endl;

    return answer;
}