#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

std::map<std::string, char> MappingPitch;

class MusicInfo
{
public:
    MusicInfo()
    {

    }

    MusicInfo(const std::string& _Info)
    {
        std::vector<std::string> CurMusicInfos(4, "");
        std::string Temp = "";
        std::stringstream CurSS(_Info);
        int Index = 0;

        while (std::getline(CurSS, Temp, ','))
        {
            CurMusicInfos[Index] = Temp;
            ++Index;
        }

        StartTime = CurMusicInfos[0];
        EndTime = CurMusicInfos[1];
        MusicName = CurMusicInfos[2];
        Melody = CurMusicInfos[3];

        std::string ChangeM = "";
        std::string PrevPitch = "";
        const size_t MeloodyLength = Melody.length();

        for (size_t i = 0; i < MeloodyLength; ++i)
        {
            if ('#' != Melody[i])
            {
                ChangeM += PrevPitch;
                PrevPitch = Melody[i];

                if (i == MeloodyLength - 1)
                {
                    ChangeM += PrevPitch;
                }
            }
            else
            {
                PrevPitch += Melody[i];
                ChangeM += MappingPitch[PrevPitch];
                PrevPitch = "";
            }
        }

        Melody = ChangeM;

        CalculatePlayTime();
        MakePlayMelody();
    }

    std::string GetStartTime() const
    {
        return StartTime;
    }

    std::string GetPlayMelody() const
    {
        return PlayMelody;
    }

    int GetPlayTime() const
    {
        return PlayTime;
    }

    std::string GetMusicName() const
    {
        return MusicName;
    }

private:
    void CalculatePlayTime()
    {
        int StartHour = std::stoi(StartTime.substr(0, 2));
        int EndHour = std::stoi(EndTime.substr(0, 2));

        int StartSecond = std::stoi(StartTime.substr(3, 2));
        int EndSecond = std::stoi(EndTime.substr(3, 2));

        if (EndSecond < StartSecond)
        {
            EndHour -= 1;
            EndSecond += 60;
        }

        PlayTime = (EndSecond - StartSecond) + 60 * (EndHour - StartHour);
    }

    void MakePlayMelody()
    {
        int Index = 0;

        while (PlayMelody.length() != PlayTime)
        {
            PlayMelody += Melody[Index];
            ++Index;

            if (Index == Melody.length())
            {
                Index = 0;
            }
        }
    }

private:
    std::string StartTime = "";
    std::string EndTime = "";
    std::string MusicName = "";
    std::string Melody = "";

    int PlayTime = 0;
    std::string PlayMelody = "";
};

std::string solution(std::string m, std::vector<std::string> musicinfos)
{
    std::string answer = "";

    MappingPitch.insert(std::make_pair("A#", 'H'));
    MappingPitch.insert(std::make_pair("C#", 'I'));
    MappingPitch.insert(std::make_pair("D#", 'J'));
    MappingPitch.insert(std::make_pair("F#", 'K'));
    MappingPitch.insert(std::make_pair("G#", 'L'));

    std::string ChangeM = "";
    std::string PrevPitch = "";
    const size_t mLength = m.length();

    for (size_t i = 0; i < mLength; ++i)
    {
        if ('#' != m[i])
        {
            ChangeM += PrevPitch;
            PrevPitch = m[i];

            if (i == mLength - 1)
            {
                ChangeM += PrevPitch;
            }
        }
        else
        {
            PrevPitch += m[i];
            ChangeM += MappingPitch[PrevPitch];
            PrevPitch = "";
        }
    }

    MusicInfo AnswerMI;

    for (const std::string& CurMusicInfo : musicinfos)
    {
        MusicInfo CurMI = MusicInfo(CurMusicInfo);

        std::string CurPlayMelody = CurMI.GetPlayMelody();

        size_t FindIndex = CurPlayMelody.find(ChangeM);

        if (FindIndex == std::string::npos)
        {
            continue;
        }

        if (answer == "")
        {
            AnswerMI = CurMI;
            answer = CurMI.GetMusicName();
        }
        else
        {
            if (AnswerMI.GetPlayTime() < CurMI.GetPlayTime())
            {
                AnswerMI = CurMI;
                answer = CurMI.GetMusicName();
            }
            else if (AnswerMI.GetPlayTime() == CurMI.GetPlayTime())
            {
                if (AnswerMI.GetStartTime() > CurMI.GetStartTime())
                {
                    AnswerMI = CurMI;
                    answer = CurMI.GetMusicName();
                }
            }
        }
    }

    if (answer == "")
    {
        answer = "(None)";
    }

    return answer;
}