#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int getIndexOfExist(map<string, vector<string>> m, vector<string> s) {
	int index = 0;
	for (auto item : m) {
		if (item.second == s) {
			break;
		}
		index++;
	}
	return index;
}

bool contains(map<string, vector<string>> m, vector<string> v) {
	for (auto item : m) {
		if (item.second == v) {
			return true;
		}
	}
	return false;
}

int main() {
	vector<string> buffer;
	map<string, vector<string>> result;
	int q, count;
	string stop;
	vector<string> tmp;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> count;
		for (int j = 0; j < count; j++) {
			cin >> stop;
			tmp.push_back(stop);
		}
		if (contains(result, tmp)) {
			buffer.push_back("Already exists for " + to_string(getIndexOfExist(result, tmp)+1));
		} else {
			int size = result.size() + 1;
			string name = "New bus " + to_string(size);
			result[name] = (tmp);
			buffer.push_back(name);
		}
		tmp.clear();
	}

	for (string s : buffer) {
		cout << s << endl;
	}
	return 0;
}
/*
4
2 Marushkino Kokoshkino
1 Kokoshkino
2 Marushkino Kokoshkino
2 Kokoshkino Marushkino

5
2 Marushkino Kokoshkino
1 Kokoshkino
2 Marushkino Kokoshkino
1 Kokoshkino
2 Kokoshkino Marushkino

3
2 A B
2 A B
2 A B

*/
