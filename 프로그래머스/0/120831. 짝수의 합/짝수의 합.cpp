int solution(int n)
{
    int answer = 0;
    
    for(int i = 2; i <= n; ++i)
    {
        if(i & 1 == 1)
        {
            continue;
        }
        
        answer += i;
    }
    
    return answer;
}