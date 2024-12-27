#include <bits/stdc++.h>
using namespace std;

bool Solve(string X, string Y) {
	if (X.compare(Y) == 0) {  // X == Y
		return true;
    }
	// if X="" and Y="", return true; (but this condition is not needed)
	if (X.length() <= 1) {  // if length of X is 1, then it is not equal to Y as if it was equal then previous if statement would return true
		return false;
    }
	int n = X.length();
	int flag = false;
	for (int i = 1; i <= n - 1; i++) {   // Note :- We can't into empty substring
		if ((Solve(X.substr(0, i), Y.substr(n - i, i)) && Solve(X.substr(i, n-i), Y.substr(0, n - i))) || // these are two condition for swapping and not swapping the string 
		        (Solve(X.substr(0, i), Y.substr(0, i)) && Solve(X.substr(i, n-i), Y.substr(i, n-i)))) {
			flag = true; 
			break;
		}
	}
	return flag;
}

int main() {
	string X, Y; cin >> X >> Y;
	if (X.length() != Y.length())  // if length is not equal, then return false
		cout << "No\n";
	else
		Solve(X, Y) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}
