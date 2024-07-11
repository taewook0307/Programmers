#include <string>
#include <vector>
#include <stack>

using namespace std;

void MoveStackData(stack<int>* ReqStack, stack<int>* ResStack)
{
    ResStack->push(ReqStack->top());
    ReqStack->pop();
}

int solution(vector<int> ingredient) {
    int answer = 0;

    vector<int> HamburgerRecipe = { 1, 2, 3, 1 };
    stack<int> ingredientStack;
    stack<int> CheckIngredientStack;

    for (int CurIngredient : ingredient)
    {
        ingredientStack.push(CurIngredient);

        if (4 <= ingredientStack.size())
        {
            if (HamburgerRecipe[3] == ingredientStack.top())
            {
                MoveStackData(&ingredientStack, &CheckIngredientStack);

                if (HamburgerRecipe[2] == ingredientStack.top())
                {
                    MoveStackData(&ingredientStack, &CheckIngredientStack);

                    if (HamburgerRecipe[1] == ingredientStack.top())
                    {
                        MoveStackData(&ingredientStack, &CheckIngredientStack);

                        if (HamburgerRecipe[0] == ingredientStack.top())
                        {
                            MoveStackData(&ingredientStack, &CheckIngredientStack);

                            answer += 1;

                            while (!CheckIngredientStack.empty())
                            {
                                CheckIngredientStack.pop();
                            }
                        }
                        else
                        {
                            while (!CheckIngredientStack.empty())
                            {
                                MoveStackData(&CheckIngredientStack, &ingredientStack);
                            }
                        }
                    }
                    else
                    {
                        while (!CheckIngredientStack.empty())
                        {
                            MoveStackData(&CheckIngredientStack, &ingredientStack);
                        }
                    }
                }
                else
                {
                    while (!CheckIngredientStack.empty())
                    {
                        MoveStackData(&CheckIngredientStack, &ingredientStack);
                    }
                }
            }
        }
    }

    return answer;
}