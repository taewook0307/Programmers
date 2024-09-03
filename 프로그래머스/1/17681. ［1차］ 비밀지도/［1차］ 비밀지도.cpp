#include <string>
#include <vector>
#include <bitset>
#include <regex>

std::string DecimalToBinary(int _Value, int _Size)
{
    std::string BinaryValue = std::bitset<16>(_Value).to_string();

    const int SliceIndex = 16 - _Size;

    std::string ReturnValue = BinaryValue.substr(SliceIndex, _Size);

    for (int i = 0; i < _Size; ++i)
    {
        if ('0' == ReturnValue[i])
        {
            ReturnValue[i] = ' ';
        }
        else
        {
            ReturnValue[i] = '#';
        }
    }

    return ReturnValue;
}

std::vector<std::string> solution(int n, std::vector<int> arr1, std::vector<int> arr2)
{
    std::vector<std::string> answer;
    answer.reserve(arr1.size());

    for (int i = 0; i < n; ++i)
    {
        arr1[i] = arr1[i] | arr2[i];
    }

    std::vector<std::string> ChangeBinary;

    for (int i = 0; i < n; ++i)
    {
        std::string BinaryNum = DecimalToBinary(arr1[i], n);
        
        BinaryNum = std::regex_replace(BinaryNum, std::regex("1"), "#");
        BinaryNum = std::regex_replace(BinaryNum, std::regex("0"), " ");

        answer.push_back(BinaryNum);
    }

    return answer;
}