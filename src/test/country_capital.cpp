/*
vector<string> buffer;

void ChangeCapital(map<string, string>& m, string country, string new_capital) {
	if (m.count(country) == 0) {
		m[country] = new_capital;
		buffer.push_back("Introduce new country " + country + " with capital " + new_capital);
	} else if (m[country] == new_capital) {
		buffer.push_back("Country " + country + " hasn't changed its capital");
	} else if (m[country] != new_capital){
		buffer.push_back("Country " + country + " has changed its capital from " +
				m[country] + " to " + new_capital);
		m[country] = new_capital;
	}
}

void Rename(map<string, string>& m, string old_country, string new_country) {
	if ((old_country == new_country) || (m.count(old_country) == 0) || (m.count(new_country) > 0)) {
		buffer.push_back("Incorrect rename, skip");
	} else if (m[old_country] != ""){
		m[new_country] = m[old_country];
		m.erase(old_country);
		buffer.push_back("Country " + old_country + " with capital " +
				m[new_country] + " has been renamed to " + new_country);
	}
}

void About(map<string, string>& m, string country) {
	if (m.count(country) == 0) {
		buffer.push_back("Country " + country + " doesn't exist");
	} else if ((m.count(country) != 0) && (m[country] != "")){
		buffer.push_back("Country " + country + " has capital " + m[country]);
	}
}

void Dump(map<string, string>& m) {
	if (m.size() == 0) {
		buffer.push_back("There are no countries in the world");
	} else {
		string tmp = "";
		for (auto pair : m) {
			tmp +=  pair.first + "/" + pair.second + " ";
		}
		tmp = tmp.substr(0, tmp.size()-1);
		buffer.push_back(tmp);
	}
}

void printResult(const vector<string>& buffer) {
	for (string s : buffer) {
		cout << s << endl;
	}
}

int main() {
	int q;
	string country, new_capital, old_country, new_country;
	string command;
	cin >> q;
	map<string, string> m;
	for (int i = 0; i < q; i++) {
		cin >> command;
		if (command == "CHANGE_CAPITAL") {
			cin >> country >> new_capital;
			ChangeCapital(m, country, new_capital);
		} else if (command == "RENAME") {
			cin >> old_country >> new_country;
			Rename(m, old_country, new_country);
		} else if (command == "ABOUT") {
			cin >> country;
			About(m, country);
		} else if (command == "DUMP") {
			Dump(m);
		}
	}

	printResult(buffer);
	return 0;
}
*/
