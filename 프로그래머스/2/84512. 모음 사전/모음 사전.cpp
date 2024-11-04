#include <string>
#include <vector>
#include <map>

int solution(std::string word)
{
    int answer = 0;

    std::vector<int> Value = { 781, 156, 31, 6, 1 };

    std::map<int, char> Factor;
    Factor.insert(std::make_pair('A', 1));
    Factor.insert(std::make_pair('E', 2));
    Factor.insert(std::make_pair('I', 3));
    Factor.insert(std::make_pair('O', 4));
    Factor.insert(std::make_pair('U', 5));

    const size_t WordLength = word.length();

    for (size_t i = 0; i < WordLength; ++i)
    {
        answer += (Factor[word[i]] - 1) * Value[i] + 1;
    }

    return answer;
}