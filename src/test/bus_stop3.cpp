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

int main() {
//	int q,count;
//	int busIndex = 1;
//	map<set<string>, int> m;
//	map<set<string>, int> n;
//	map<set<string>, int> s;
	set<string> tmp;
	tmp.insert("");
//	string stop;
//	cin >> q;
//
//	for (int i = 0; i < q; i++) {
//		cin >> count;
//		for (int j = 0; j < count; count++) {
//			cin >> stop;
//			tmp.insert(stop);
//		}
//		if (m[tmp] > 0) {
//			AddToBuffer("Already exists for " + to_string(m[tmp]));
//		} else {
//			m[tmp] = busIndex;
//			busIndex++;
//			AddToBuffer("New bus " + to_string(busIndex));
//		}
//	}
//
//	PrintBuffer();
	return 0;
}
