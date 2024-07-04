#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";
    
    int Count = str1.size(); 
    
    for(int i = 0; i < Count; ++i)
    {
        answer += str1[i];
        answer += str2[i];
    }
    
    return answer;
}