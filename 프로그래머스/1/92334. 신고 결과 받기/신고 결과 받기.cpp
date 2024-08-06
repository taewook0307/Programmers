#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    const int id_listCount = id_list.size();
    vector<int> answer(id_listCount);

    // 플레이어와 인덱스 맵핑
    unordered_map<std::string, int> IdMap;

    for (int i = 0; i < id_listCount; ++i)
    {
        IdMap.insert(make_pair(id_list[i], i));
    }

    // report 중복 내용 제거 다른 방법
    //std::sort(report.begin(), report.end());
    //report.erase(std::unique(report.begin(), report.end()), report.end());

    // report 중복 내용 제거
    set<string> ReportSet;
    for (string ReportContent : report)
    {
        ReportSet.insert(ReportContent);
    }

    // 신고된 횟수
    vector<int> ReportCount(id_listCount);

    // 정지당한 플레이어
    set<std::string> BannedPlayer;

    // report 내용
    unordered_multimap<string, string> Report;

    for (string ReportList : ReportSet)
    {
        size_t BlankIndex = ReportList.find(' ');

        // 신고자와 피신고인으로 구별
        string Reporter = ReportList.substr(0, BlankIndex);
        string ReportedPlayer = ReportList.substr(BlankIndex + 1, ReportList.size() - BlankIndex);

        Report.insert(make_pair(ReportedPlayer, Reporter));

        int Index = IdMap[ReportedPlayer];
        ++ReportCount[Index];

        if (k <= ReportCount[Index])
        {
            BannedPlayer.insert(ReportedPlayer);
        }
    }

    unordered_multimap<string, string>::iterator StartIter = Report.begin();
    unordered_multimap<string, string>::iterator EndIter = Report.end();

    for (; StartIter != EndIter; ++StartIter)
    {
        if (BannedPlayer.end() != BannedPlayer.find(StartIter->first))
        {
            int Index = IdMap[StartIter->second];

            ++answer[Index];
        }
    }
    
    return answer;
}