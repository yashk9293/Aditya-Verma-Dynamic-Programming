#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> mp;

bool Solve(string X, string Y) {
	string key = X + " " + Y;
	if (mp.find(key) != mp.end()) // if we did not found the and travesed upto end of the map 
		return mp[key];

	if (X.compare(Y) == 0) {
		mp[key] = true;
		return true;
	}
	if (X.length() <= 1) {
		mp[key] = false;
		return false;
	}

	int n = X.length();
	bool flag = false;
	for (int i = 1; i <= n - 1; i++) {
		if ((Solve(X.substr(0, i), Y.substr(n - i, i)) && Solve(X.substr(i), Y.substr(0, n - i))) ||
		        (Solve(X.substr(0, i), Y.substr(0, i)) && Solve(X.substr(i), Y.substr(i)))) {
			flag = true;
			break;
		}
	}
	return mp[key] = flag; // store in table for further reference 
}

int main() {
	string X, Y; cin >> X >> Y;

	mp.clear();

	if (X.length() != Y.length())
		cout << "No\n";
	else
		Solve(X, Y) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}