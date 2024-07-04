#include <string>
#include <vector>

using namespace std;

string solution(vector<string> arr) {
    string answer = "";
    
    for(string CurString : arr)
    {
        answer += CurString;
    }
    
    return answer;
}