#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (vector<int> Command : commands)
    {
        vector<int> SliceArray;

        const int Start = Command[0] - 1;
        const int End = Command[1] - 1;
        const int AnswerNum = Command[2] - 1;

        for (int i = Start; i <= End; ++i)
        {
            SliceArray.push_back(array[i]);
        }

        sort(SliceArray.begin(), SliceArray.end());

        const int AnswerValue = SliceArray[AnswerNum];

        answer.push_back(AnswerValue);
    }
    
    return answer;
}