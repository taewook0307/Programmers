#include <vector>
#include <numeric>

double solution(std::vector<int> numbers)
{
    int Sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    double answer = static_cast<double>(Sum) / static_cast<double>(numbers.size());   
    return answer;
}