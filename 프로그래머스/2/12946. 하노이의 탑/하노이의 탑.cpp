#include <vector>

void Hanoi(std::vector<std::vector<int>>* _VectorPtr, int _N, int _Start, int _Sub, int _End)
{
    if(_N == 1)
    {
        std::vector<int> PushVector = {_Start, _End};
        _VectorPtr->push_back(PushVector);        
    }
    else
    {
        Hanoi(_VectorPtr, _N - 1, _Start, _End, _Sub);
        std::vector<int> PushVector = {_Start, _End};
        _VectorPtr->push_back(PushVector);
        Hanoi(_VectorPtr, _N - 1, _Sub, _Start, _End);
    }
}

std::vector<std::vector<int>> solution(int n)
{
    std::vector<std::vector<int>> answer;
    answer.reserve(n * n);
    
    Hanoi(&answer, n, 1, 2, 3);
    
    return answer;
}