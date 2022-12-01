#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Day
{
	public:
		void PrintAnswers();
	protected:
		virtual void SolvePartOne() = 0;
		virtual void SolvePartTwo() = 0;

		int m_partOneAnswer;
		int m_partTwoAnswer;
};

