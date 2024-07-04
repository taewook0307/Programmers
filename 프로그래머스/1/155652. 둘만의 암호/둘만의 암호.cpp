#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for (int i = 0; i < s.size(); ++i)
    {
        char CurChar = s[i];
        int RealMoveCount = 0;
        int MoveCount = 1;

        while (RealMoveCount != index)
        {
            char MoveChar = CurChar + MoveCount;

            if (MoveChar > 'z')
            {
                MoveCount -= MoveCount;
                CurChar = 'a';
                MoveChar = 'a';
            }

            if (std::string::npos != skip.find(MoveChar))
            {
                ++MoveCount;
                continue;
            }

            ++MoveCount;
            ++RealMoveCount;

            if (RealMoveCount == index)
            {
                CurChar = MoveChar;
            }
        }

        answer += CurChar;
    }
    
    return answer;
}