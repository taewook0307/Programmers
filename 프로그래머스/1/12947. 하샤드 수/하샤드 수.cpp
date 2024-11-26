bool solution(int x)
{
    int CopyX = x;
    
    int Sum = 0;
    
    while(CopyX != 0)
    {
        Sum += CopyX % 10;
        CopyX /= 10;
    }
    
    return (x % Sum) == 0;
}