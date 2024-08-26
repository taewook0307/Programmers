#include <string>
#include <vector>
#include <unordered_map>

std::vector<int> solution(std::vector<std::string> name, std::vector<int> yearning, std::vector<std::vector<std::string>> photo)
{
    const int photoCount = static_cast<int>(photo.size());

    std::vector<int> answer;
    answer.reserve(photoCount);

    // 사람과 점수 Mapping
    std::unordered_map<std::string, int> ScoreMap;
    
    const int nameCount = static_cast<int>(name.size());

    for (int i = 0; i < nameCount; ++i)
    {
        ScoreMap.insert(std::make_pair(name[i], yearning[i]));
    }

    // 사진별 점수 구하기
    for (const std::vector<std::string>& CurPhoto : photo)
    {
        int Score = 0;
        const int CurPhotoPeople = static_cast<int>(CurPhoto.size());

        for (int i = 0; i < CurPhotoPeople; ++i)
        {
            int PersonScore = ScoreMap[CurPhoto[i]];

            Score += PersonScore;
        }

        answer.push_back(Score);
    }

    return answer;
}