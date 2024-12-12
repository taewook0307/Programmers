#include <vector>

std::vector<int> solution(std::vector<int> numbers, int num1, int num2)
{
    std::vector<int> answer(num2 - num1 + 1, 0);

    copy(numbers.begin() + num1, numbers.begin() + num2 + 1, answer.begin());

    return answer;
}