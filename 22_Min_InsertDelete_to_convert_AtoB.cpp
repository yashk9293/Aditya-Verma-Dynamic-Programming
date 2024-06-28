// Question Link :- https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
// Minimum number of deletions and insertions

// T.C = O(n*m)
// S.C = O(n*m)
class Solution {
	public:
	int LCS(string X, string Y, int m, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (Y[i - 1] == X[j - 1]) { 
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
    
	int minOperations(string X, string Y) {
	    int m = X.length(), n = Y.length();
	    int deletions = m - LCS(X, Y, m, n);
	    int insertions = n - LCS(X, Y, m, n);
	    
	    return deletions + insertions;
	}
};


// Input :-
// heap
// pea

// Output :-
// 3 (deletions = 2 + insertions = 1)
