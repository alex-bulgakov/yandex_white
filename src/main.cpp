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

//void addToBoffer(string s) { // функция для добавления строки в буфер
//	buffer.push_back(s);
//}

//void printBuffer() { // напечатать буфер
//	for (string s : buffer) {
//		cout << s << endl;
//	}
//}

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

vector<string> BusesForStop(map<string, vector<string>>& m, string& stop) { // обработка BUSES_FOR_STOP
	vector<string> result;
	for (string bus : keys) { // соблюдаем порядок записи автобусов
		if (Contains(m[bus], stop)) {
			result.push_back(bus);
		}
	}
	return result;
}

void StopsForBus(map<string, vector<string>>& m, string& bus) { // обработка STOPS_FOR_BUS
string result = "";
if (m.count(bus) == 0) {
//	addToBoffer("No bus");
	cout << "No bus" << endl;
} else {
	for (string s : m[bus]) {
		vector<string> bfs = BusesForStop(m, s);
		if ((bfs.size() == 1) && (bfs[0]== bus)) {
			result = "Stop " + s + ": no interchange";
		} else {
			string tmp = "";
			for (string s : bfs) {
				if (s != bus) {
					tmp += s + " ";
				}
			}
			result = "Stop " + s + ": " + tmp.substr(0, tmp.size()-1);
		}
//		addToBoffer(result.substr(0, (result.size())));
		cout << result.substr(0, result.size()) << endl;
	}
}
}

void AllBuses(map<string, vector<string>>& m) { // обработка ALL_BUSES
string result = "";
if (m.size() == 0) {
//	addToBoffer("No buses");
	cout << "No buses" << endl;
} else {
	for (auto item : m) {
		result = "Bus " + item.first + ": ";
		for (string s : item.second) {
			result += s + " ";
		}
//		addToBoffer(result.substr(0, result.size() - 1));
		cout << result.substr(0, result.size() - 1) << endl;
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
		vector<string> tmp = BusesForStop(m, stop);
		if (tmp.size()==0) {
//			addToBoffer("No stop");
			cout << "No stop" << endl;
		} else {
			string str = "";
			for (string s : tmp) {
				str += s + " ";
			}
//			addToBoffer(str.substr(0, str.size()-1));
			cout << str.substr(0, str.size()-1) << endl;
		}
	} else if (command == "STOPS_FOR_BUS") {
		cin >> bus;
		StopsForBus(m, bus);
	} else if (command == "ALL_BUSES") {
		AllBuses(m);
	}
}
//printBuffer();
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

 8
 NEW_BUS 100 4 a1 a2 a3 a4
 NEW_BUS 101 3 a1 a2 a3
 ALL_BUSES
 BUSES_FOR_STOP a2
 BUSES_FOR_STOP a4
 STOPS_FOR_BUS 101
 STOPS_FOR_BUS 100
 STOPS_FOR_BUS 99



 * */

