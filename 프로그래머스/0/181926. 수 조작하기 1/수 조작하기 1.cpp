#include <string>
#include <vector>

int solution(int n, std::string control)
{
    int answer = n;
    
    for(char c : control)
    {
        switch(c)
        {
            case 'w':
                answer += 1;
                break;
            case 's':
                answer -= 1;
                break;
            case 'd':
                answer += 10;
                break;
            case 'a':
                answer -= 10;
                break;
            default:
                break;
        }
    }
    
    return answer;
}