#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

/*
 * tests
 */

int main() {
	vector<int> day_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<vector<string>> todo(31);
	string command, s;
	int i, q;
	int current_month = 0;

	for (int j = 0; j < q; j++) {
		cin >> command;
		if (command == "ADD") {
			cin >> i >> s;
			todo[i-1].push_back(s);
		} else if (command == "NEXT") {
			if (current_month > 11) current_month = 0;
			current_month++;
			if (day_months[current_month] > todo.size()) {
				todo.resize(current_month);
			} else if (day_months[current_month] < todo.size()) {
				for (int i = current_month; i < todo.size(); i++) {

				}
			}
		}
	}

	return 0;
}
