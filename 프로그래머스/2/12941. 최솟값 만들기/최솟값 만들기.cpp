#include <iostream>
#include<vector>
#include <algorithm>

int solution(std::vector<int> A, std::vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), std::greater<int>());

    const size_t Count = A.size() < B.size() ? A.size() : B.size();

    for (size_t i = 0; i < Count; ++i)
    {
        int PlusValue = A[i] * B[i];
        answer += PlusValue;
    }

    std::cout << answer << std::endl;

    return answer;
}