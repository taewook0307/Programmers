#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

std::vector<int> solution(int n, std::vector<std::string> words)
{
    std::vector<int> answer(2);

    std::unordered_set <std::string> SetWords;
    std::string LastPushWord = "";

    int DropCount = -1;

    for (const std::string& CurWord : words)
    {
        // 한글자 확인
        if (CurWord.size() == 1)
        {
            DropCount = SetWords.size() + 1;
            break;
        }

        // 끝말 확인
        if (LastPushWord != "" && CurWord[0] != *LastPushWord.rbegin())
        {
            DropCount = SetWords.size() + 1;
            break;
        }

        std::pair<std::unordered_set<std::string>::iterator, bool> Push = SetWords.insert(CurWord);
        LastPushWord = CurWord;

        // 중복 문자 확인
        if (false == Push.second)
        {
            DropCount = SetWords.size() + 1;
            break;
        }
    }

    if (DropCount == -1)
    {
        return answer;
    }

    if (DropCount % n == 0)
    {
        answer[0] = n;
    }
    else
    {
        answer[0] = DropCount % n;
    }

    answer[1] = ceil(DropCount / static_cast<float>(n));

    return answer;
}