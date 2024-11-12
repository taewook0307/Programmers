#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

bool Compare(const std::tuple<std::string, int, int>& _Left, const std::tuple<std::string, int, int>& _Right)
{
    std::string LeftHeader = std::get<0>(_Left);
    std::string RightHeader = std::get<0>(_Right);

    int LeftNum = std::get<1>(_Left);
    int RightNum = std::get<1>(_Right);

    int LeftIndex = std::get<2>(_Left);
    int RightIndex = std::get<2>(_Right);

    if (LeftHeader == RightHeader)
    {
        if (LeftNum == RightNum)
        {
            return LeftIndex < RightIndex;
        }

        return LeftNum < RightNum;
    }

    return LeftHeader < RightHeader;
}

std::vector<std::string> solution(std::vector<std::string> files)
{
    const size_t FileCount = files.size();
    std::vector<std::string> answer;
    answer.reserve(FileCount);

    std::vector<std::tuple<std::string, int, int>> FileDatas;
    FileDatas.reserve(FileCount);

    for (size_t i = 0; i < FileCount; ++i)
    {
        std::string CurFile = files[i];
        size_t Len = CurFile.length();

        std::string Header = "";
        std::string NumString = "";

        bool Flag = false;

        for (size_t j = 0; j < Len; ++j)
        {
            if (false == Flag)
            {
                if (CurFile[j] >= '0' && CurFile[j] <= '9')
                {
                    NumString += CurFile[j];
                    Flag = true;
                    continue;
                }
                
                Header += std::tolower(CurFile[j]);
            }
            else
            {
                if (CurFile[j] >= '0' && CurFile[j] <= '9' && NumString.size() < 5)
                {
                    NumString += CurFile[j];
                    continue;
                }

                break;
            }
        }

        FileDatas.push_back(std::make_tuple(Header, std::stoi(NumString), i));
    }

    std::sort(FileDatas.begin(), FileDatas.end(), Compare);

    for (const std::tuple<std::string, int, int>& CurTuple : FileDatas)
    {
        int Index = std::get<2>(CurTuple);
        answer.push_back(files[Index]);
    }

    return answer;
}