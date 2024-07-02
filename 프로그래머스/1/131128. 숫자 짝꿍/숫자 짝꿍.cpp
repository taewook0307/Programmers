#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    vector<int> XNumberCount;
    XNumberCount.resize(10);
    vector<int> YNumberCount;
    YNumberCount.resize(10);
    
    const int XSize = X.size();
    const int YSize = Y.size();

    for (int i = 0; i < XSize; ++i)
    {
        char CurData = X[i] - '0';
        int IndexNum = CurData;

        int PrevValue = XNumberCount[IndexNum];
        XNumberCount[IndexNum] = PrevValue + 1;
    }

    for (int i = 0; i < YSize; ++i)
    {
        char CurData = Y[i] - '0';
        int IndexNum = CurData;
    
        int PrevValue = YNumberCount[IndexNum];
        YNumberCount[IndexNum] = PrevValue + 1;
    }
    
    for (int i = 9; i >= 0; --i)
    {
        int Count = XNumberCount[i] < YNumberCount[i] ? XNumberCount[i] : YNumberCount[i];

        for (int j = 0; j < Count; ++j)
        {
            answer += std::to_string(i);
        }
    }
    
    if (0 == answer.size())
    {
        return "-1";
    }

    if ('0' == answer[0])
    {
        return "0";
    }
    
    return answer;
}