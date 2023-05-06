#include "Functions.h"

#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <map>

int GetRBits(int m)
{
	for (size_t r = 2; ; r++)
	{
		if (static_cast<int>(std::pow(2, r)) >= m + r + 1)
		{
			return r;
		}
	}
}

std::vector<int> DecToBit(int number, size_t size)
{
	std::vector<int> bits;

	for (int i = size - 1; i >= 0; i--)
	{
		int bit = (number >> i) & 1;
		bits.push_back(bit);
	}

	return bits;
}


std::ostream& operator<<(std::ostream& out, const std::map<char, std::vector<int>>& table)
{
	auto printChrar = [](char ch) -> std::string
	{
		std::stringstream ostr;
		ostr << "'";

		switch (ch)
		{
		case '\n':
			ostr << "\\n'";
			break;

		case '\t':
			ostr << "\\t'";
			break;

		default:
			ostr << ch << "'";
			break;
		}

		return ostr.str();
	};

	for (const auto& item : table)
	{
		out << std::setw(4) << printChrar(item.first) << "  ";
		for (auto elem : item.second)
		{
			out << elem << " ";
		}
		out << std::endl;
	}

	return out;
}

std::vector<int> HammingCode(const std::vector<int>& data, size_t r)
{
	std::vector<int> result;
	result.resize(r + data.size());

	for (size_t i = 0, j = 0; i < result.size(); i++)
	{
		if (log2(i + 1) == floor(log2(i + 1)))
		{
			result[i] = 0;
		}
		else
		{
			result[i] = data[j];
			j++;
		}
	}

	for (size_t i = 0; i < r; i++)
	{
		int iter = std::pow(2, i);
		int count = 0;
		bool isSpace = false;

		int countIter = 0;
		for (size_t j = iter - 1; j < result.size(); j++)
		{
			if (!isSpace)
			{
				countIter++;
				count += result[j];
				if (countIter == iter)
				{
					countIter = 0;
					isSpace = true;
				}
			}
			else if (isSpace)
			{
				countIter++;
				if (countIter == iter)
				{
					countIter = 0;
					isSpace = false;
				}
			}
		}

		result[iter - 1] = count % 2;
	}

	return result;
}

char ToLover(char character)
{
	switch (character)
	{
	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;

	case '�':
		return '�';
		break;
	}

	return std::tolower(character);
}