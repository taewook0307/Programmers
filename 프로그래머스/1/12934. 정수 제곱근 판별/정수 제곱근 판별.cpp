#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    double RootN = sqrt(static_cast<double>(n));
    long long ChangeRootN = static_cast<long long>(RootN);

    if (RootN == ChangeRootN)
    {
        answer = (ChangeRootN + 1) * (ChangeRootN + 1);
    }
    else
    {
        answer = -1;
    }

    return answer;
}