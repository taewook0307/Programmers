#include <string>
#include <vector>

std::vector<int> solution(int n, long long left, long long right)
{
    long long Size = right - left + 1;
    std::vector<int> answer;
    answer.reserve(static_cast<size_t>(Size));

    for (long long i = left; i <= right; ++i)
    {
        long long row = i / n;
        long long column = i % n;

        int IntRow = static_cast<int>(row);
        int IntColumn = static_cast<int>(column);

        int PushValue = IntRow < IntColumn ? IntColumn + 1 : IntRow + 1;

        answer.push_back(PushValue);
    }

    return answer;
}