#pragma once

#include <iostream>
#include <vector>
#include <map>


char ToLover(char character);

/// <summary>
/// 2^r >= m + r + 1 
/// </summary>
/// <param name="m"> - кількість інформаціних бітів</param>
/// <param name="r"> - кількість контрольних бітів</param>
/// <returns>кількість контрольних бітів</returns>
int GetRBits(int m);

std::ostream& operator<<(std::ostream& out, const std::map<char, std::vector<int>>& table);

/// <summary>
/// Конвертує код на вході в код Хеммінга.
/// </summary>
/// <param name="data"> - код, який конвертується</param>
/// <param name="r"> - кількість контрольних бітів</param>
/// <returns>вектор, що представляє код Хеммінга.</returns>
std::vector<int> HammingCode(const std::vector<int>& data, size_t r);

/// <summary>
/// Конвертує число з десяткової системи в двійкову.
/// </summary>
/// <param name="number"> - число, яке треба конвертувати </param>
/// <param name="size"> - кількість бітів, якими число має бути представлене </param>
/// <returns>вектор, що представляє бітовий формат числа.</returns>
std::vector<int> DecToBit(int number, size_t size = sizeof(int) * 8);