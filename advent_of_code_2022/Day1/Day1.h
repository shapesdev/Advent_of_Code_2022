#pragma once
#include "../Base/Day.h"

class Day1 : public Day
{
	public:
		Day1();

	private:
		void ReadInput();
		void SolvePartOne();
		void SolvePartTwo();
		multimap<int, int> m_elfCaloriesMap;
};

