#pragma once
#include "../Base/Day.h"

struct Pair {
	int min;
	int max;
};

class Day4 : public Day
{
public:
	Day4();

private:
	void ReadInput();
	void SolvePartOne();
	void SolvePartTwo();

	vector<Pair> m_Inputs;
};