#include <vector>
#include <iostream>
using namespace std;

bool IsPrimeNumber(int num)
{
    for(int i = 2; i < num; ++i)
    {
        int RemainValue = num % i;
        
        if(0 == RemainValue)
        {
            return false;
        }
    }
    
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    const int numsSize = nums.size();
    
    for(int i = 0; i < numsSize - 2; ++i)
    {
        for(int j = i + 1; j < numsSize - 1; ++j)
        {
            for(int k = j + 1; k < numsSize; ++k)
            {
                const int firstNumber = nums[i];
                const int secondNumber = nums[j];
                const int thirdNumber = nums[k];
                
                const int sumNum = firstNumber + secondNumber + thirdNumber;
                
                bool Check = IsPrimeNumber(sumNum);
                
                if(true == Check)
                {
                    ++answer;
                }
            }
        }
    }
    
    return answer;
}