#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

bool CheckAvailable(const char _Value)
{
    if ('a' <= _Value && 'z' >= _Value
        || '0' <= _Value && '9' >= _Value
        || '-' == _Value
        || '_' == _Value
        || '.' == _Value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string solution(string new_id) {
    string answer = "";
    deque<char> Change_Id;

    char PrevChar = NULL;

    const int new_idSize = new_id.size();

    for (int i = 0; i < new_idSize; ++i)
    {
        // 1단계
        new_id[i] = tolower(new_id[i]);
        
        //2단계
        if (false == CheckAvailable(new_id[i]))
        {
            continue;
        }

        //3단계
        if (NULL != PrevChar && '.' == PrevChar && '.' == new_id[i])
        {
            continue;
        }

        Change_Id.push_back(new_id[i]);
        PrevChar = new_id[i];
    }

    // 4단계
    while (false == Change_Id.empty() && '.' == Change_Id.front())
    {
        Change_Id.pop_front();
    }

    while (false == Change_Id.empty() && '.' == Change_Id.back())
    {
        Change_Id.pop_back();
    }

    // 5단계
    if (0 == Change_Id.size())
    {
        Change_Id.push_back('a');
    }

    // 6단계
    while (15 < Change_Id.size())
    {
        Change_Id.pop_back();
    }

    // 7단계
    while (3 > Change_Id.size())
    {
        char LastChar = Change_Id.back();

        Change_Id.push_back(LastChar);
    }

    // 4단계
    while (false == Change_Id.empty() && '.' == Change_Id.front())
    {
        Change_Id.pop_front();
    }

    while (false == Change_Id.empty() && '.' == Change_Id.back())
    {
        Change_Id.pop_back();
    }

    while (false == Change_Id.empty())
    {
        char CurChar = Change_Id.front();

        answer += CurChar;
        Change_Id.pop_front();
    }

    return answer;
}