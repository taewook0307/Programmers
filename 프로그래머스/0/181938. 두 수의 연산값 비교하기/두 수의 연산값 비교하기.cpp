#include <string>
#include <vector>

int solution(int a, int b)
{
    int AB = stoi(std::to_string(a) + std::to_string(b));
    int AB2 = 2 * a * b;

    return AB > AB2 ? AB : AB2;
}