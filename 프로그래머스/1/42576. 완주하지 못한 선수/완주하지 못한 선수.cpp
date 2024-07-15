#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_multiset<std::string> ParticipantSet;

    for (string ParticipantName : participant)
    {
        ParticipantSet.insert(ParticipantName);
    }

    for (string CompletionName : completion)
    {
        unordered_multiset<string>::iterator FindIter = ParticipantSet.find(CompletionName);

        ParticipantSet.erase(FindIter);
    }

    answer = ParticipantSet.begin()->c_str();

    return answer;
}