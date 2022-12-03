#pragma once
#include "../Base/Day.h"

class Day3 : public Day
{
public:
	Day3();

private:
	void ReadInput();
	void SolvePartOne();
	void SolvePartTwo();
	void CalculatePriority(int& total, char& letter);

	vector<string> m_Inputs;
};