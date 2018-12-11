#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
vector<string> buffer;

void addToBoffer(string s) {
	buffer.push_back(s);
}

void printBuffer() {
	for (string s : buffer) {
		cout << s << endl;
	}
}

void NewBus(map<string, vector<string>>& m, string bus, int stop_count) {
	string stop;
	for (int i = 1; i <= stop_count; i++) {
		cin >> stop;
		m[bus].push_back(stop);
	}
}

bool Contains(const vector<string>& v, string search) {
	if (find(v.begin(), v.end(), search) != v.end()) {
		return true;
	} else {
		return false;
	}
}
string BusesForStop(map<string, vector<string>>& m, string stop) {
	string result = "";
	for (auto item : m) {
		if (Contains(item.second, stop)) {
			result += item.first + " ";
		}
	}
	return result.substr(0, result.size() - 1);
}

void StopsForBus(map<string, vector<string>>& m, string bus) {
	string tmp = "";
	if (m.count(bus) == 0) {
		addToBoffer("No bus");
	} else {
		for (string s : m[bus]) {
			tmp = BusesForStop(m, s);
			int pos = tmp.find(bus);
			tmp = tmp.erase(pos, bus.size());
			if (tmp == "") {
				tmp = " no interchange";
			}
			addToBoffer("Stop " + s + ":" + tmp);
		}
	}
}

void AllBuses(map<string, vector<string>>& m) {
	string result = "";
	if (m.size() == 0) {
		addToBoffer("No buses");
	} else {
		for (auto item : m) {
			result = "Bus " + item.first + ": ";
			for (string s : item.second) {
				result += s + " ";
			}
			addToBoffer(result.substr(0, result.size() - 1));
		}
	}
}
int main() {
	map<string, vector<string>> m;
	int q, stop_count;
	string command, bus, stop;
	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> command;
		if (command == "NEW_BUS") {
			cin >> bus >> stop_count;
			NewBus(m, bus, stop_count);
		} else if (command == "BUSES_FOR_STOP") {
			cin >> stop;
			string tmp = BusesForStop(m, stop);
			if (tmp == "") {
				addToBoffer("No stop");
			} else {
				addToBoffer(tmp);
			}
		} else if (command == "STOPS_FOR_BUS") {
			cin >> bus;
			StopsForBus(m, bus);
		} else if (command == "ALL_BUSES") {
			AllBuses(m);
		}
	}
	printBuffer();
	return 0;
}
