#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int Solve(string X, int i, int j, bool isTrue) {
	string key = to_string(i) + " " + to_string(j) + " " + (isTrue ? "T" : "F");
	if (mp.find(key) != mp.end())
		return mp[key];

    if (i > j) {
        return false;
    }
	if (i == j) {
		if (isTrue)
			mp[key] = X[i] == 'T';
		else
			mp[key] = X[i] == 'F';
		return mp[key];
	}

	int ans = 0;
	for (int k = i + 1; k < j; k += 2) {
		int l_T = Solve(X, i, k - 1, true);
		int l_F = Solve(X, i, k - 1, false);
		int r_T = Solve(X, k + 1, j, true);
		int r_F = Solve(X, k + 1, j, false);

		if (X[k] == '|') {
			if (isTrue == true)
				ans += l_T * r_T + l_T * r_F + l_F * r_T;
			else
				ans += l_F * r_F;
		}
		else if (X[k] == '&') {
			if (isTrue == true)
				ans += l_T * r_T;
			else
				ans += l_T * r_F + l_F * r_T + l_F * r_F;
		}
		else if (X[k] == '^') {
			if (isTrue == true)
				ans += l_T * r_F + l_F * r_T;
			else
				ans += l_T * r_T + l_F * r_F;
		}

	}

	return mp[key] = ans;
}

signed main() {
	string X; cin >> X;
	mp.clear();
	cout << Solve(X, 0, X.length() - 1, true) << endl;
	return 0;
}