#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;

    if (a == b)
    {
        return a;
    }

    long long BigValue = a < b ? (long long)b : (long long)a;
    long long SmallValue = a < b ? (long long)a : (long long)b;

    long long PlusOneToBigger = BigValue * (BigValue + 1) / 2;
    long long PlusOneToSmall = SmallValue * (SmallValue + 1) / 2;

    answer = PlusOneToBigger - PlusOneToSmall + SmallValue;

    return answer;
}