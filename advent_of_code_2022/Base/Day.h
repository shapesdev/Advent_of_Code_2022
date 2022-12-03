#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

class Day
{
	public:
		void PrintAnswers();
	protected:
		virtual void SolvePartOne() = 0;
		virtual void SolvePartTwo() = 0;
		virtual void ReadInput() = 0;

		int m_PartOneAnswer;
		int m_PartTwoAnswer;
		int m_Day = 0;
};

