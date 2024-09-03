#include <string>
#include <vector>

std::string DecimalToBinary(int _Value, int _Size)
{
    std::string ReturnValue;
    ReturnValue.reserve(_Size);

    int ChangeValue = _Value;
    std::string ChangeValueString;
    while (ChangeValue > 0)
    {
        int RemainValue = ChangeValue % 2;
        if (0 == RemainValue)
        {
            ChangeValueString.push_back(' ');
        }
        else
        {
            ChangeValueString.push_back('#');
        }
        
        ChangeValue /= 2;
    }

    const int ChangeValueSize = static_cast<int>(ChangeValueString.size());

    if (ChangeValueSize < _Size)
    {
        int PushCount = _Size - ChangeValueSize;
        for (int i = 0; i < PushCount; ++i)
        {
            ReturnValue.push_back(' ');
        }
    }

    for (int i = (ChangeValueSize - 1); i >= 0; --i)
    {
        ReturnValue.push_back(ChangeValueString[i]);
    }

    return ReturnValue;
}

std::vector<std::string> solution(int n, std::vector<int> arr1, std::vector<int> arr2)
{
    const int Arr1Size = arr1.size();

    std::vector<std::string> answer;
    answer.reserve(Arr1Size);

    std::vector<std::string> AnalysisArr1;
    AnalysisArr1.reserve(Arr1Size);

    for (int Num : arr1)
    {
        AnalysisArr1.push_back(DecimalToBinary(Num, n));
    }

    std::vector<std::string> AnalysisArr2;
    AnalysisArr2.reserve(Arr1Size);

    for (int Num : arr2)
    {
        AnalysisArr2.push_back(DecimalToBinary(Num, n));
    }

    for (int i = 0; i < Arr1Size; ++i)
    {
        std::string PushString;
        PushString.reserve(n);

        for (int j = 0; j < n; ++j)
        {
            char Arr1Value = AnalysisArr1[i][j];
            char Arr2Value = AnalysisArr2[i][j];

            if (' ' == Arr1Value && ' ' == Arr2Value)
            {
                PushString.push_back(' ');
            }
            else
            {
                PushString.push_back('#');
            }
        }

        answer.push_back(PushString);
    }

    return answer;
}