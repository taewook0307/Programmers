using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    
    long long Fee = 0;
    
    for(int i = 1; i <= count; ++i)
    {
        Fee += price * i;
    }
    
    answer = static_cast<long long>(money) - Fee;

    return answer > 0 ? 0 : -answer;
}