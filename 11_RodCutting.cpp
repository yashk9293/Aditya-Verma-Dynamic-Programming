// Note :- https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

// The first approach that comes to our mind is greedy. A greedy solution will fail in this problem 
// because there is no ‘uniformity’ in data. While selecting a local better choice we may choose an 
// item that will in long term give less value.

// As the greedy approach doesn’t work, we will try to generate all possible combinations using 
// recursion and select the combination which gives us the maximum value in the given constraints.

#include <bits/stdc++.h>
using namespace std;

int getMaxProfit(int length[], int price[], int n, int L) {
	int t[n + 1][L + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= L; j++) {
			if (i == 0) {
				t[i][j] = 0;
			}
			if (j == 0) {
				t[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= L; j++) {
			if (length[i - 1] <= j) {
				t[i][j] = max(price[i - 1] + t[i][j - length[i - 1]], t[i - 1][j]);
			}
			else {
				t[i][j] = t[i - 1][j];
			}
		}
	}
	return t[n][L];
}

signed main() {
	int n; cin >> n;
	int length[n], price[n];
	for (int i = 0; i < n; i++) {
		cin >> length[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	int L;
	cin >> L;

	cout << getMaxProfit(length, price, n, L) << endl;
	return 0;
}
