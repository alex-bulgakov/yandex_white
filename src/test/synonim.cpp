#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

vector<string> buffer;

void AddToBuffer(string s) {
	buffer.push_back(s);
}

void PrintBuffer() {
	for (string s : buffer) {
		cout << s << endl;
	}
}


bool Contains(const vector<set<string>>& s, const string& str) {
	for (set<string> i : s) {
		if (i.count(str) > 0) {
			return true;
		}
	}
	return false;
}

void Add(map<string, set<string>>& m, string w1, string w2) {
	m[w1].insert(w2);
	m[w2].insert(w1);
}

int Count(map<string, set<string>>& m, string w) {
	return m[w].size();
}

bool Check(map<string, set<string>>& m, string w1, string w2) {
	if (m[w1].count(w2) > 0) {
		return true;
	}
	return false;
}

int main() {
	int q;
	map<string, set<string>> m;
	string command, w1, w2;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> command;
		if (command == "ADD") {
			cin >> w1 >> w2;
			Add(m, w1, w2);
		} else if (command == "COUNT") {
			cin >> w1;
			AddToBuffer(to_string(Count(m, w1)));
		} else if (command == "CHECK") {
			cin >> w1 >> w2;
			if (Check(m, w1, w2)) {
				AddToBuffer("YES");
			} else {
				AddToBuffer("NO");
			}
		}
	}
	PrintBuffer();
	return 0;
}
