#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

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

    std::set<char> OverlapMenu;
    std::set<std::string> OverlapMenuString;

    const size_t OrderCount = orders.size();

    // 주문서 중 한 번이라도 겹치는 메뉴 확인
    for (size_t i = 0; i < OrderCount - 1; ++i)
    {
        std::string StandardOrder = orders[i];

        for (size_t j = i + 1; j < OrderCount; ++j)
        {
            std::string CheckOrder = orders[j];

            for (char Menu : CheckOrder)
            {
                if (std::string::npos != StandardOrder.find(Menu))
                {
                    OverlapMenu.insert(Menu);
                    OverlapMenuString.insert(std::string(1, Menu));
                }
            }
        }
    }

    // 한 번이라도 겹친 메뉴들로 만들 수 있는 모든 조합 제조
    int MaxCourseCount = course[course.size() - 1];
    std::vector<std::set<std::string>> AllCourse;
    AllCourse.resize(MaxCourseCount);
    AllCourse[0] = OverlapMenuString;

    for (int i = 1; i < MaxCourseCount; ++i)
    {
        std::set<std::string> MakeCourse = AllCourse[i];
        const std::set<std::string>& PrevSet = AllCourse[i - 1];

        for (const std::string& CurCourse : PrevSet)
        {
            char LastChar = CurCourse[CurCourse.size() - 1];

            for (char Menu : OverlapMenu)
            {
                if (Menu > LastChar)
                {
                    std::string PlusCourse = CurCourse;
                    PlusCourse.push_back(Menu);
                    MakeCourse.insert(PlusCourse);
                }
            }
        }

        AllCourse[i] = MakeCourse;
    }

    // 만들어진 조합 중 2개 이상 포함되는 주문 내용은 Course에 추가
    std::map<std::string, int, OrderStandard> Course;

    for (int CourseCount : course)
    {
        std::set<std::string> CountAllCourse = AllCourse[CourseCount - 1];

        std::set<std::string>::iterator BeginIter = CountAllCourse.begin();
        std::set<std::string>::iterator EndIter = CountAllCourse.end();

        int MaxCount = -1;

        for (; BeginIter != EndIter; ++BeginIter)
        {
            int Count = 0;

            for (const std::string& Order : orders)
            {
                bool IsOrder = true;

                for (char Menu : *BeginIter)
                {
                    if (std::string::npos == Order.find(Menu))
                    {
                        IsOrder = false;
                        break;
                    }
                }

                if (true == IsOrder)
                {
                    ++Count;
                }
            }

            if (Count > 1)
            {
                // 이미 들어간 문자 중 최대 크기의 문자보다 큰 경우만 insert
                if (Count >= MaxCount)
                {
                    Course.insert(std::make_pair(*BeginIter, Count));
                    MaxCount = Count;
                }                
            }
        }
    }

    // 해당 조합 중 가장 많은 Course 요리 추가
    for (int CourseMenuCount : course)
    {
        std::map<std::string, int>::iterator BeginIter = Course.begin();
        std::map<std::string, int>::iterator EndIter = Course.end();

        int MaxCount = -1;
        std::vector<std::string> PlusFactor;
        PlusFactor.reserve(Course.size());

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

    // 정렬
    sort(answer.begin(), answer.end());

    return answer;
}