#pragma once

#include <iostream>
#include <vector>
#include <map>


char ToLover(char character);

/// <summary>
/// 2^r >= m + r + 1 
/// </summary>
/// <param name="m"> - ������� ������������ ���</param>
/// <param name="r"> - ������� ����������� ���</param>
/// <returns>������� ����������� ���</returns>
int GetRBits(int m);

std::ostream& operator<<(std::ostream& out, const std::map<char, std::vector<int>>& table);

/// <summary>
/// �������� ��� �� ���� � ��� �������.
/// </summary>
/// <param name="data"> - ���, ���� ������������</param>
/// <param name="r"> - ������� ����������� ���</param>
/// <returns>������, �� ����������� ��� �������.</returns>
std::vector<int> HammingCode(const std::vector<int>& data, size_t r);

/// <summary>
/// �������� ����� � ��������� ������� � �������.
/// </summary>
/// <param name="number"> - �����, ��� ����� ������������ </param>
/// <param name="size"> - ������� ���, ����� ����� �� ���� ������������ </param>
/// <returns>������, �� ����������� ������ ������ �����.</returns>
std::vector<int> DecToBit(int number, size_t size = sizeof(int) * 8);