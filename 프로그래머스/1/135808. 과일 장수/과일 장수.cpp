#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    const int AppleCount = score.size();

    multiset<int, greater<int>> SortScore;

    for (int AppleScore : score)
    {
        SortScore.insert(AppleScore);
    }

    int BoxCount = AppleCount / m;
    int SellCount = m * BoxCount;

    multiset<int>::iterator StartIter = SortScore.begin();
    multiset<int>::iterator EndIter = SortScore.end();

    int i = 0;
    int MinScore = k;
    for (; StartIter != EndIter; ++StartIter)
    {
        int CurScore = *StartIter;
        
        if (MinScore > CurScore)
        {
            MinScore = CurScore;
        }

        ++i;

        if (0 == i % m)
        {
            answer += (MinScore * m);
        }

        if (i >= SellCount)
        {
            break;
        }
    }

    return answer;
}