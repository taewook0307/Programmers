#include <string>
#include <vector>

std::vector<int> solution(std::vector<int> num_list)
{
    std::vector<int> answer = num_list;

    int LastNum = num_list.back();

    num_list.pop_back();

    int LastNumFinishPop = num_list.back();

    int PushNum = (LastNumFinishPop < LastNum) ? (LastNum - LastNumFinishPop) : (LastNum * 2);

    answer.push_back(PushNum);

    return answer;
}