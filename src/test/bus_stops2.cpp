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
	int index = 1;
	vector<string> buffer;
	map<vector<string>, int> result;
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
		if (result.count(tmp) > 0) {
			buffer.push_back("Already exists for " + to_string(result.at(tmp)));
		} else {
			result[tmp] = index;
			buffer.push_back("New bus " + to_string(index));
			index++;
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

3
1 a
1 b
1 c

4
1 a
1 b
1 a
1 b

5
2 Marushkino Kokoshkino
1 Kokoshkino
2 Marushkino Kokoshkino
2 Kokoshkino Marushkino
2 Kokoshkino Marushkino


*/
