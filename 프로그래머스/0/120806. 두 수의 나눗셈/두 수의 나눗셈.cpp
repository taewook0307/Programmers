int solution(int num1, int num2)
{
    float Remain = static_cast<float>(num1) / static_cast<float>(num2);
    Remain *= 1000;
    return static_cast<int>(Remain);
}