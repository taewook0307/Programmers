#include <string>
#include <vector>

bool solution(bool x1, bool x2, bool x3, bool x4)
{
    bool answer = (x1 || x2) && (x3 || x4);
    return answer;
}