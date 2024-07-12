#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    const int playerNum = players.size();
    answer.reserve(playerNum);

    unordered_map<string, int> PlayerSequence;
    map<int, string> PlayerName;

    for (int i = 0; i < playerNum; i++)
    {
        PlayerSequence.insert(make_pair(players[i], i));
        PlayerName.insert(make_pair(i, players[i]));
    }

    for (string CurPlayer : callings)
    {
        // 이름이 호명된 플레이어 순위
        int CurPlayerSequence = PlayerSequence[CurPlayer];

        // 호명된 플레이어의 앞에 있는 플레이어 이름
        string PrevName = PlayerName[CurPlayerSequence - 1];

        // 앞에 있는 플레이어 순위
        int PrevPlayerSequence = PlayerSequence[PrevName];

        // 변경
        int Temp = CurPlayerSequence;
        PlayerSequence[CurPlayer] = PrevPlayerSequence;
        PlayerSequence[PrevName] = Temp;
        
        // PlayerName
        PlayerName.erase(CurPlayerSequence);
        PlayerName.erase(PrevPlayerSequence);

        PlayerName.insert(make_pair(PrevPlayerSequence, CurPlayer));
        PlayerName.insert(make_pair(Temp, PrevName));
    }
    
    map<int, string>::iterator BeginIter = PlayerName.begin();
    map<int, string>::iterator EndIter = PlayerName.end();

    for (; BeginIter != EndIter; ++BeginIter)
    {
        string CurName = BeginIter->second;
        answer.push_back(CurName);
    }

    return answer;
}