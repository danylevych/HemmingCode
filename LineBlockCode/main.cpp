#include <iostream>
#include <vector>
#include <iomanip>

int GetBinaryAdd(const std::vector<int>& data)
{
	int result = 0;

	for (auto elem : data)
	{
		if (elem == 1 && result == 1)
		{
			result = 0;
		}
		else
		{
			result += elem;
		}
	}

	return result;
}

std::vector<std::vector<int>> GetLinearCode(const std::vector<std::vector<int>>& defCode,
											const std::vector<std::vector<int>>& createMatrix)
{
	std::vector<std::vector<int>> result;
	result.resize(defCode.size());

	std::vector<int> multRes;

	for (size_t k = 0; k < defCode.size(); k++)
	{
		for (size_t i = 0; i < createMatrix[0].size(); i++)
		{
			multRes.clear();
			for (size_t j = 0; j < defCode[0].size(); j++)
			{
				multRes.push_back(defCode[k][j] * createMatrix[j][i]);
			}
			result[k].push_back(GetBinaryAdd(multRes));
		}
	}

	return result;
}

int main()
{
	std::vector<std::vector<int>> defCode
	{
		{0, 0, 0, 0},
		{0, 0, 0, 1},
		{0, 0, 1, 0},
		{0, 0, 1, 1},
		{0, 1, 0, 0},
		{0, 1, 0, 1},
		{0, 1, 1, 0},
		{0, 1, 1, 1},
		{1, 0, 0, 0},
		{1, 0, 0, 1},
		{1, 0, 1, 0},
		{1, 0, 1, 1}
	};

	std::vector<std::vector<int>> createMatrix
	{
		{1, 0, 0, 0, 0, 1, 1},
		{0, 1, 0, 0, 1, 0, 1},
		{0, 0, 1, 0, 1, 1, 0},
		{0, 0, 0, 1, 1, 1, 1},
	};

	auto resultCode = GetLinearCode(defCode, createMatrix);

	int count = 1;
	for (const auto& elems : resultCode)
	{
		std::cout << std::setw(4) << count << ") " ;
		for (int elem : elems)
		{
			std::cout << elem << " ";
		}
		std::cout << std::endl;
		count++;
	}

	return 0;
}