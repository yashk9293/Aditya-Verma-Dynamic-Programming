// Notes :- https://www.geeksforgeeks.org/longest-common-subsequence-dp-4

#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1];

	// initialize 1st row and of dp matrix with 0 according to the base condition of recursion 
    // base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
		}
	}
    // choise diagram is used to fill rest of the matrix 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (X[i - 1] == Y[j - 1]) {   // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {   // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	return dp[n][m];
}
