#include <iostream>
#include <fstream>

#include "Functions.h"
#include <Windows.h>
#include <string>
#include <vector>
#include <map>


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::map<char, std::vector<int>> table;

	std::ifstream file("Data.txt");

	if (!file)
	{
		std::cerr << "Error opening file!" << std::endl;
		std::exit(-1);
	}

	while (file.good())
	{
		char character{};
		file.get(character);

		if (character != char{})
		{
			table.insert(std::pair<char, std::vector<int>>(ToLover(character), {}));
		}
	}
	file.close();


	size_t sizeOfUnCode = std::ceil(std::log2(table.size()));
	{
		size_t i = 0;
		for (auto& elem : table)
		{
			elem.second = DecToBit(i, sizeOfUnCode);
			i++;
		}
	}

	std::cout << "\n\nРівномірний код:\n";
	std::cout << table;

	size_t m = table.begin()->second.size();
	size_t r = GetRBits(m);

	std::map<char, std::vector<int>> hammingTable = table;
	for (auto& item : hammingTable)
	{
		item.second = HammingCode(item.second, r);
	}

	std::cout << "\n\nКод Хеммінга:\n";
	std::cout << hammingTable;

	return 0;
}