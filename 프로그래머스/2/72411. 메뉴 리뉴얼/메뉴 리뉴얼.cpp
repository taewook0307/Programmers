#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

class Course
{
public:
    Course(const std::string& _Value)
        : Order(_Value)
    {

    }

    std::set<std::string> MakeCourse(int _Count)
    {
        std::set<std::string> ReturnSet;

        if (_Count == 1)
        {
            for (char Menu : Order)
            {
                ReturnSet.insert(std::string(1, Menu));
            }

            return ReturnSet;
        }

        std::set<std::string> PrevSet = MakeCourse(_Count - 1);

        for (const std::string& Course : PrevSet)
        {
            char LastMenu = Course[Course.size() - 1];

            for (char Menu : Order)
            {
                std::string PlusCourse = Course;
                if (LastMenu < Menu)
                {
                    PlusCourse += Menu;
                    ReturnSet.insert(PlusCourse);
                }
            }
        }

        return ReturnSet;
    }

private:
    std::string Order = "";
};

struct OrderStandard
{
    bool operator() (const std::string& _Left, const std::string& _Right) const
    {
        if (_Left.size() == _Right.size())
        {
            return _Left < _Right;
        }
        else
        {
            return _Left.size() < _Right.size();
        }
    }
};

std::vector<std::string> solution(std::vector<std::string> orders, std::vector<int> course)
{
    std::vector<std::string> answer;
    answer.reserve(orders.size());

    // 만든 조합과 조합을 가지고 있는 개수
    std::map<std::string, int, OrderStandard> CourseCount;

    for (std::string& Order : orders)
    {
        sort(Order.begin(), Order.end());
    }

    for (int Count : course)
    {
        // 현재 오더로 조합 만들기
        for (const std::string& Order : orders)
        {
            Course CurOrderCourse = Course(Order);
            std::set<std::string> CurOrderSet = CurOrderCourse.MakeCourse(Count);

            for (const std::string& MakeCourse : CurOrderSet)
            {
                if (CourseCount.end() != CourseCount.find(MakeCourse))
                {
                    CourseCount[MakeCourse] += 1;
                }
                else
                {
                    CourseCount.insert(std::make_pair(MakeCourse, 1));
                }
            }
        }
    }

    std::map<std::string, int>::iterator BeginIter = CourseCount.begin();
    std::map<std::string, int>::iterator EndIter = CourseCount.end();

    for (; BeginIter != EndIter;)
    {
        if (BeginIter->second == 1)
        {
            BeginIter = CourseCount.erase(BeginIter);
        }
        else
        {
            ++BeginIter;
        }
    }

    for (int CourseMenuCount : course)
    {
        std::map<std::string, int>::iterator BeginIter = CourseCount.begin();
        std::map<std::string, int>::iterator EndIter = CourseCount.end();

        int MaxCount = -1;
        std::vector<std::string> PlusFactor;
        PlusFactor.reserve(CourseCount.size());

        for (; BeginIter != EndIter; ++BeginIter)
        {
            if (CourseMenuCount == BeginIter->first.size())
            {
                if (MaxCount < BeginIter->second && 1 < BeginIter->second)
                {
                    PlusFactor.clear();
                    MaxCount = BeginIter->second;
                    PlusFactor.push_back(BeginIter->first);
                }
                else if (MaxCount == BeginIter->second)
                {
                    PlusFactor.push_back(BeginIter->first);
                }
                else
                {
                    continue;
                }
            }
            else if (CourseMenuCount < BeginIter->first.size())
            {
                break;
            }
        }

        for (const std::string& PlusCourse : PlusFactor)
        {
            answer.push_back(PlusCourse);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}