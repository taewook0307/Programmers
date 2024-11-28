#include <string>
#include <vector>
#include <map>

int solution(std::vector<std::string> babbling)
{
    int answer = 0;

    std::map<std::string, std::string> Words;
    Words.insert(std::make_pair("aya", "1"));
    Words.insert(std::make_pair("ye", "2"));
    Words.insert(std::make_pair("woo", "3"));
    Words.insert(std::make_pair("ma", "4"));

    for (const std::string& CurBabbling : babbling)
    {
        std::string ChangeValue = CurBabbling;

        std::map<std::string, std::string>::iterator BeginIter = Words.begin();
        std::map<std::string, std::string>::iterator EndIter = Words.end();

        for (;BeginIter != EndIter; ++BeginIter)
        {
            while (ChangeValue.find(BeginIter->first) != std::string::npos)
            {
                size_t FindNum = ChangeValue.find(BeginIter->first);
                ChangeValue.replace(FindNum, BeginIter->first.length(), BeginIter->second);
            }
        }

        bool Flag = true;

        for (char C : ChangeValue)
        {
            if (false == isdigit(C))
            {
                Flag = false;
                break;
            }
        }

        if (Flag == false)
        {
            continue;
        }

        int Num = atoi(ChangeValue.c_str());

        int PrevNum = -1;
        while (Num != 0)
        {
            int CurNum = Num % 10;

            if (CurNum == PrevNum)
            {
                Flag = false;
                break;
            }

            PrevNum = CurNum;
            Num /= 10;
        }

        if (true == Flag)
        {
            ++answer;
        }
    }

    return answer;
}