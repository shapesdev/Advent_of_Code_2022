#include "Day2.h"

Day2::Day2() {
	day = 2;
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
	m_partOneAnswer = total;
}

void Day2::SolvePartTwo() {

}