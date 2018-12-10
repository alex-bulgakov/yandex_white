/*
void Add(vector<vector<string>>& v, string s, int i) {
	v[i-1].push_back(s);
}

void Next(vector<vector<string>>& v, int size) {
	for (int i = size; i < v.size(); i++) {
		v[size-1].insert(end(v[size-1]), begin(v[i]), end(v[i]));
	}
	v.resize(size);
}

void Dump(vector<vector<string>>& v, vector<string>& result, int i) {
	string str = to_string(v[i-1].size());
	for (string s : v[i-1]) {
		str += " " + s;
	}
	result.push_back(str);
}

int main() {
	vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<string> result;
	int current_month = 0;
	int next_month = current_month + 1;
	vector<vector<string>> v(days[current_month]);
	string note, command;
	int day, q;

	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> command;
		if (command == "ADD") {
			cin >> day >> note;
			Add(v, note, day);
		} else if (command == "NEXT") {
			if (current_month > 11) {
				current_month = 0;
				next_month = 1;
			}

			if (v.size() < days[next_month]) {
				v.resize(days[next_month]);
			} else if (v.size() > days[next_month]){
				Next(v, days[next_month]);
			}

			current_month++;
			next_month = current_month + 1;
			if (next_month > 11) next_month = 0;
		} else if (command == "DUMP") {
			cin >> day;
			Dump(v, result, day);
		}
	}

	for (string s : result) {
		cout << s << endl;
	}
	return 0;
}
*/
