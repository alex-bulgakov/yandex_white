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
	for (int i = 1; i <= stop_count; i++) {
		m[bus].push_back("stop" + to_string(i));
	}
}

void BusesForStop(map<string, vector<string>>& m, string stop) {

}

int main() {
	map<string, vector<string>> m;
	NewBus(m, "bus1", 5);

	for (string s : m["bus1"]) {
		cout << s << endl;
	}
	return 0;
}
