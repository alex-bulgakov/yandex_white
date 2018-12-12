#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

vector<string> buffer; // вектор для финального вывода результата
vector<string> keys; // список автобусов в том порядке в котором они добавлялись
vector<string> keyStops; // тоже самое для остановок

bool Contains(const vector<string>& v, string search) { // функция для проверки содержится ли строка в векторе
	if (find(v.begin(), v.end(), search) != v.end()) {
		return true;
	} else {
		return false;
	}
}

void addToBoffer(string s) { // функция для добавления строки в буфер
	buffer.push_back(s);
}

void printBuffer() { // напечатать буфер
	for (string s : buffer) {
		cout << s << endl;
	}
}

void NewBus(map<string, vector<string>>& m, string bus, int stop_count) { // функция обработки запроса NEW_BUS
	string stop;
	for (int i = 1; i <= stop_count; i++) {
		cin >> stop;
		m[bus].push_back(stop);
		if (!Contains(keys, bus)) {
			keys.push_back(bus);
		}
		if (!Contains(keyStops, stop)) {
			keyStops.push_back(stop);
		}
	}
}


string BusesForStop(map<string, vector<string>>& m, string stop) { // обработка BUSES_FOR_STOP
	string result = "";
	for (string bus : keys) { // соблюдаем порядок записи автобусов
		if (Contains(m[bus], stop)) {
			result += bus + " ";
		}
	}
	if (result != "") {
		return result.substr(0, result.size() - 1);
	} else {
		return "";
	}
}

void StopsForBus(map<string, vector<string>>& m, string bus) { // обработка STOPS_FOR_BUS
	string result = "";
	if (m.count(bus) == 0) {
		addToBoffer("No bus");
	} else {
		for (string s : m[bus]) {
			result = BusesForStop(m, s);
			if (result == bus) {
				result = "Stop " + s + ": no interchange ";
			} else {
				int pos = result.find(bus);
				result = " " + result.erase(pos, bus.size());
				result = "Stop " + s + ":" + result;
			}
			addToBoffer(result.substr(0, (result.size() - 1)));
		}
	}
}

void AllBuses(map<string, vector<string>>& m) { // обработка ALL_BUSES
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

/*
 3
 STOPS_FOR_BUS 10
 STOPS_FOR_BUS 99
 ALL_BUSES

 2
 NEW_BUS 10A 2 a b
 STOPS_FOR_BUS 20B

 4
 NEW_BUS Bus3 3 stop1 stop2 stop3
 NEW_BUS Bus2 2 stop4 stop1
 NEW_BUS ABus1 1 stop5
 ALL_BUSES

 10
ALL_BUSES
BUSES_FOR_STOP Marushkino
STOPS_FOR_BUS 32K
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
BUSES_FOR_STOP Vnukovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
STOPS_FOR_BUS 272
ALL_BUSES

4
NEW_BUS bus2 3 stop1 stop2 stop0
NEW_BUS 1bus 1 stop1
NEW_BUS abus 2 stop1 stop5
BUSES_FOR_STOP stop1

4
NEW_BUS bus2 3 stop1 stop2 stop0
NEW_BUS 1bus 1 stop1
NEW_BUS abus 3 stop1 stop5 astop
STOPS_FOR_BUS abus

 * */

