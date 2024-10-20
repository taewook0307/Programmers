#include <string>
#include <stack>

int solution(std::string s)
{
    int answer = 0;

    const size_t RollCount = s.size();
    std::stack<char> Check;

    for (size_t i = 0; i < RollCount; ++i)
    {
        size_t Index = i;
        for (size_t j = 0; j < RollCount; ++j)
        {
            if (true == Check.empty())
            {
                Check.push(s[Index]);
            }
            else
            {
                char PushChar = s[Index];
                char InChar = Check.top();

                if (PushChar - InChar == 2 || PushChar - InChar == 1)
                {
                    Check.pop();
                }
                else
                {
                    Check.push(PushChar);
                }
            }

            if (Index + 1 == RollCount)
            {
                Index = 0;
            }
            else
            {
                ++Index;
            }
        }

        if (0 == Check.size())
        {
            ++answer;
        }
        else
        {
            while (Check.empty() != true)
            {
                Check.pop();
            }
        }
    }

    return answer;
}