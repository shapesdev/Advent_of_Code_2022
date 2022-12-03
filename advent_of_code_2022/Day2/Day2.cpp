#include "Day2.h"

Day2::Day2() {
	m_Day = 2;
	ReadInput();
	SolvePartOne();
	SolvePartTwo();
}

void Day2::ReadInput() {
	string line;
	ifstream file("Day2/input.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			if (!line.empty()) {
				m_Inputs.push_back(line);
			}
		}
		file.close();
	}
	else {
		cout << "Unable to open file";
	}
}

void Day2::SolvePartOne() {
	int total = 0;
	for (auto& it : m_Inputs) {
		int myShape = (int)it[2] % 87;
		total += myShape;
		for (int i = 0; i < 3; i++) {
			if (wins[i] == it) {
				total += 6;
				break;
			}
			else if (draws[i] == it) {
				total += 3;
				break;
			}
		}
	}
	m_PartOneAnswer = total;
}

void Day2::SolvePartTwo() {
	int total = 0;
	for (auto& it : m_Inputs) {
		char myShape = it[2];
		if (myShape == 'Z') {
			CheckStrategy(wins, it, total, 6);
		}
		else if (myShape == 'Y') {
			CheckStrategy(draws, it, total, 3);
		}
		else {
			CheckStrategy(losses, it, total, 0);
		}
	}
	m_PartTwoAnswer = total;
}

void Day2::CheckStrategy(string arr[], string input, int &total, int conditionValue) {
	for (int i = 0; i < 3; i++) {
		if (arr[i][0] == input[0]) {
			int shape = (int)arr[i][2] % 87;
			total += shape + conditionValue;
		}
	}
}