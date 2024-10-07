#include <vector>

void MakeCombi(int n, std::vector<long long>& _Vector)
{
    size_t VectorSize = _Vector.size();

    for (size_t i = VectorSize; i <= n; ++i)
    {
        long long PushValue = (_Vector[i - 1] + _Vector[i - 2]) % 1234567;
        _Vector.push_back(PushValue);
    }
}

long long solution(int n)
{
    long long answer = 1;

    std::vector<long long> Combi;
    Combi.reserve(n);

    // 1칸 이동
    Combi.push_back(1);
    // 2칸 이동
    Combi.push_back(2);

    MakeCombi(n, Combi);

    answer = Combi[n - 1];

    return answer;
}