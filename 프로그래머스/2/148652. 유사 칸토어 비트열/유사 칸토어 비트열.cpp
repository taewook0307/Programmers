int solution(int n, long long l, long long r)
{
    int answer = 0;
    
    for (long long i = l; i <= r; ++i)
    {
        bool flag = true;

        if (i % 5 == 3)
        {
            continue;
        }

        long long Area = i;

        while (1) {
            if (Area % 5 == 0)
            {
                Area = Area / 5;
            }
            else
            {
                Area = (Area / 5) + 1;
            }

            if (Area % 5 == 3)
            {
                flag = 0;
                break;
            }
            else if (Area <= 5)
            {
                flag = 1;
                break;
            }
        }

        if (true == flag)
        {
            ++answer;
        }
    }

    return answer;
}