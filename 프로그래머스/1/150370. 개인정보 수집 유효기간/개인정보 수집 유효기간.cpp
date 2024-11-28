#include <string>
#include <vector>
#include <map>

std::vector<int> solution(std::string today, std::vector<std::string> terms, std::vector<std::string> privacies)
{
    std::vector<int> answer;

    const size_t PrivacieCount = privacies.size();

    answer.reserve(PrivacieCount);

    std::map<char, int> TermMap;

    for (const std::string& Term : terms)
    {
        int Mouth = std::stoi(Term.substr(2));

        TermMap.insert(std::make_pair(Term[0], Mouth));
    }

    for (int i = 0; i < PrivacieCount; ++i)
    {
        std::string Date = privacies[i].substr(0, 10);
        int PlusMouth = TermMap[privacies[i][privacies[i].length() - 1]];

        int Year = std::stoi(Date.substr(0, 4));
        int Month = std::stoi(Date.substr(5, 2));
        int Day = std::stoi(Date.substr(8));

        Month += PlusMouth;

        while (Month > 12)
        {
            Month -= 12;
            ++Year;
        }

        int TodayYear = std::stoi(today.substr(0, 4));
        int TodayMonth = std::stoi(today.substr(5, 2));
        int TodayDay = std::stoi(today.substr(8));

        if (TodayYear < Year)
        {
            continue;
        }
        else if (TodayYear == Year)
        {
            if (TodayMonth < Month)
            {
                continue;
            }
            else if (TodayMonth == Month)
            {
                if (TodayDay < Day)
                {
                    continue;
                }
                else
                {
                    answer.push_back(i + 1);
                }
            }
            else
            {
                answer.push_back(i + 1);
            }
        }
        else
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}