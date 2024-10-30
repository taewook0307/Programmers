#include <vector>

int Recursive(const std::vector<int>& _Vector, int _Index, int _Current_Sum, int _Target, bool _IsPlus)
{
    int Count = 0;

    int PlusValue = _IsPlus == true ? _Vector[_Index] : -_Vector[_Index];

    _Current_Sum += PlusValue;

    if (_Index == _Vector.size() - 1 && _Current_Sum == _Target)
    {
        return 1;
    }
    else if (_Index == _Vector.size() - 1 && _Current_Sum != _Target)
    {
        return 0;
    }

    Count += Recursive(_Vector, _Index + 1, _Current_Sum, _Target, true);
    Count += Recursive(_Vector, _Index + 1, _Current_Sum, _Target, false);

    return Count;
}

int solution(std::vector<int> numbers, int target)
{
    int answer = 0;

    answer += Recursive(numbers, 0, 0, target, true);
    answer += Recursive(numbers, 0, 0, target, false);

    return answer;
}