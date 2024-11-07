#include <iostream>
#include<string>
#include <stack>

bool solution(std::string s)
{
    bool answer = true;

    std::stack<char> StringStack;

    for (char CurChar : s)
    {
        if ('(' == CurChar)
        {
            StringStack.push(CurChar);
        }
        else if(')' == CurChar)
        {
            if (false == StringStack.empty())
            {
                char TopChar = StringStack.top();

                if (TopChar == '(')
                {
                    StringStack.pop();
                }
                else
                {
                    StringStack.push(CurChar);
                }
            }
            else
            {
                StringStack.push(CurChar);
            }   
        }
    }

    answer = StringStack.empty();

    std::cout << answer << std::endl;

    return answer;
}