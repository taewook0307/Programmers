#include <string>
#include <stack>

bool IsCorrect(std::string _Value)
{
    std::stack<char> RemainValue;
    
    for(char C : _Value)
    {
        if(true == RemainValue.empty())
        {
            RemainValue.push(C);
            continue;
        }
        
        if(')' == C && '(' == RemainValue.top())
        {
            RemainValue.pop();
        }
        else
        {
            RemainValue.push(C);
        }
    }
    
    return RemainValue.empty();
}

std::string solution(std::string p)
{
    if(p == "")
    {
        return p;
    }
    
    std::string Result = "";
    
    std::string U = "";
    std::string V = "";
    
    int OpenCount = 0;
    int CloseCount = 0;
    
    for(char C : p)
    {
        U += C;
        
        if(C == '(')
        {
            ++OpenCount;
        }
        else
        {
            ++CloseCount;
        }
        
        if(OpenCount == CloseCount)
        {
            break;
        }
    }
    
    V = p.substr(U.length());
    
    if(true == IsCorrect(U))
    {
        Result += U;
        Result += solution(V);
        return Result;
    }
    
    Result += '(';
    Result += solution(V);
    Result += ')';
    
    std::string PushString = "";
    
    size_t ULength = U.length();
    for(size_t i = 1; i < ULength - 1; ++i)
    {
        if(U[i] == '(')
        {
            PushString += ')';
        }
        else
        {
            PushString += '(';
        }
    }
    
    Result += PushString;
    return Result;
}