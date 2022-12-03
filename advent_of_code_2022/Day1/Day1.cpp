#include "Day1.h"

Day1::Day1() {
	day = 1;
	ReadInput();
	SolvePartOne();
	SolvePartTwo();
}

void Day1::ReadInput() {
	string line;
	int elf = 0;
	int cal = 0;
	ifstream file("Day1/input.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			if (line.empty()) {
				elf++;
				m_elfCaloriesMap.insert(pair<int, int>(cal, elf));
				cal = 0;
			}
			else {
				cal += stoi(line);
			}
		}
		file.close();
	}
	else {
		cout << "Unable to open file";
	}
}

void Day1::SolvePartOne() {
	int mostCalories = 0;
	map<int, int>::iterator it;
	for (it = m_elfCaloriesMap.begin(); it != m_elfCaloriesMap.end(); it++) {
		if (it->first > mostCalories) {
			mostCalories = it->first;
		}
	}
	m_partOneAnswer = mostCalories;
}

void Day1::SolvePartTwo() {
	int topThreeResults = 0;
	auto it = m_elfCaloriesMap.rbegin();
	for (int i = 0; i < 3; i++) {
		topThreeResults += it->first;
		it++;
	}
	m_partTwoAnswer = topThreeResults;
}