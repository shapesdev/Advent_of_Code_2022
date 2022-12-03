#pragma once
#include "../Base/Day.h"

class Day2 : public Day
{
	public:
		Day2();

	private:
		void ReadInput();
		void SolvePartOne();
		void SolvePartTwo();
		void CheckStrategy(string arr[], string input, int& total, int conditionValue);

		string wins[3] = { "C X", "A Y", "B Z" };
		string draws[3] = { "A X", "B Y", "C Z" };
		string losses[3] = { "A Z", "B X", "C Y" };
		vector<string> m_Inputs;
};