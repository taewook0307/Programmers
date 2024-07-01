#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    
    const int numsSize = nums.size();
    
    if(numsSize > 50 || numsSize < 3)
    {
        return answer;
    }
    
    for(int i = 0; i < numsSize - 2; ++i)
    {
        for(int j = i + 1; j < numsSize - 1; ++j)
        {
            for(int k = j + 1; k < numsSize; ++k)
            {
                const int firstNum = nums[i];
                const int secondNum = nums[j];
                const int thirdNum = nums[k];
                
                if(firstNum == secondNum
                  || secondNum == thirdNum
                  || thirdNum == firstNum)
                {
                    return answer;
                }
                
                const int sumNum = firstNum + secondNum + thirdNum;
                
                for(int a = 1; a <= sumNum; ++a)
                {
                    int RemainValue = sumNum % a;

                    if (0 == RemainValue)
                    {
                        if (1 != a && sumNum != a)
                        {
                            break;
                        }
                    }

                    if (sumNum == a)
                    {
                        if (-1 == answer)
                        {
                            answer = 1;
                        }
                        else
                        {
                            ++answer;
                        }
                    }
                }
            }
        }
    }

    return answer;
}