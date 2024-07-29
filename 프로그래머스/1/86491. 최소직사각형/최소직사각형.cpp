#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int XSize = 0;
    int YSize = 0;

    for (vector<int> BusinessCard : sizes)
    {
        int LongSize = BusinessCard[0] < BusinessCard[1] ? BusinessCard[1] : BusinessCard[0];
        int ShortSize = BusinessCard[0] < BusinessCard[1] ? BusinessCard[0] : BusinessCard[1];

        XSize = XSize < LongSize ? LongSize : XSize;
        YSize = YSize < ShortSize ? ShortSize : YSize;
    }

    answer = XSize * YSize;

    return answer;
}