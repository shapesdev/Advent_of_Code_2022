#include "Day4.h"

Day4::Day4() {
	m_Day = 4;
	ReadInput();
	SolvePartOne();
	SolvePartTwo();
}

void Day4::ReadInput() {
	string line;
	ifstream file("Day4/input.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			if (!line.empty()) {
				char minValue[2];
				char maxValue[2];
				Pair pair;

				int midPos = line.find(',');

				for (int i = 0, min = 0, max = 0; i < line.size(); i++) {
					char tempChar = line[i];
					if (i < midPos) {
						int index = line.find_first_of('-');
						if (i < index) {
							minValue[min] = line[i];
							min++;
						}
						else if(i > index) {
							maxValue[max] = line[i];
							max++;
						}
					}
					else if(i > midPos) {
						int index = line.find_last_of('-');
						if (i < index) {
							minValue[min] = line[i];
							min++;
						}
						else if (i > index) {
							maxValue[max] = line[i];
							max++;
						}
					}
					else {
						pair.min = stoi(minValue);
						pair.max = stoi(maxValue);
						m_Inputs.push_back(pair);
						cout << pair.min << " " << pair.max << endl;
;						memset(minValue, 0, sizeof(minValue));
						memset(maxValue, 0, sizeof(maxValue));
						min = 0;
						max = 0;
					}
				}
				pair.min = stoi(minValue);
				pair.max = stoi(maxValue);
				cout << pair.min << " " << pair.max << endl;
				m_Inputs.push_back(pair);
			}
		}
		file.close();
	}
	else {
		cout << "Unable to open file";
	}
}

void Day4::SolvePartOne() {

}

void Day4::SolvePartTwo() {

}