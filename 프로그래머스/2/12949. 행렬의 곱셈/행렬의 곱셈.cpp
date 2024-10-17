#include <vector>

std::vector<std::vector<int>> solution(std::vector<std::vector<int>> arr1, std::vector<std::vector<int>> arr2)
{
	const size_t Arr1Row = arr1.size();
	const size_t Arr1Column = arr1[0].size();
	const size_t Arr2Row = arr2.size();
	const size_t Arr2Column = arr2[0].size();

	std::vector<std::vector<int>> answer(Arr1Row, std::vector<int>(Arr2Column, 0));
	
	for (size_t i = 0; i < Arr1Row; ++i)
	{
		for (size_t j = 0; j < Arr2Column; ++j)
		{
			int Value = 0;

			std::vector<int> Plus = arr1[i];

			for (int k = 0; k < Arr1Column; ++k)
			{
				Value += (Plus[k] * arr2[k][j]);
			}

			answer[i][j] = Value;
		}
	}

	return answer;
}