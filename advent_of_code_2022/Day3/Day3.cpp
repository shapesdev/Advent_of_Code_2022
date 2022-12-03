#include "Day3.h"

Day3::Day3() {
	m_Day = 3;
	ReadInput();
	SolvePartOne();
	SolvePartTwo();
}

void Day3::ReadInput() {
	string line;
	ifstream file("Day3/input.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			if (!line.empty()) {
				int size = line.size();
				m_Inputs.push_back(line);
			}
		}
		file.close();
	}
	else {
		cout << "Unable to open file";
	}
}

void Day3::SolvePartOne() {
	set<char> temp;
	int total = 0;
	for (int i = 0; i < m_Inputs.size(); i++) {

		int length = m_Inputs[i].size();
		string input1 = m_Inputs[i].substr(0, length / 2);
		string input2 = m_Inputs[i].substr(length / 2, length);

		for (int j = 0; j < length / 2; j++) {
			temp.insert(input1[j]);
		}
		for (int k = 0; k < length / 2; k++) {
			if (temp.count(input2[k]) == 1) {
				CalculatePriority(total, input2[k]);
				break;
			}
		}
		temp.clear();
	}
	m_PartOneAnswer = total;
}

void Day3::SolvePartTwo() {
	map<char, int> temp;
	int total = 0;
	for (int i = 0; i < m_Inputs.size(); i += 3) {
		for (int y = 0; y < 3; y++) {
			for (int j = 0; j < m_Inputs[i + y].size(); j++) {
				if (temp[m_Inputs[i + y][j]] == y) {
					temp[m_Inputs[i + y][j]]++;
					if (temp[m_Inputs[i + y][j]] == 3) {
						CalculatePriority(total, m_Inputs[i + y][j]);
						break;
					}
				}
			}
		}
		temp.clear();
	}
	m_PartTwoAnswer = total;
}

void Day3::CalculatePriority(int& total, char& letter) {
	bool isUpper = (int)letter < 97;
	int upperOffset = 26;
	int priority = 0;

	if (isUpper) {
		priority = (int)letter % 64 + upperOffset;
	}
	else {
		priority = (int)letter % 96;
	}
	total += priority;
}