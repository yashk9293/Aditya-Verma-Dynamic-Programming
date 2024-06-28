// Question Link :- https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
// Shortest Common Supersequence

// T.C = O(m*n)
// S.C = O(m*n)

// Approach - 1 (Memoization)
class Solution {
    public:
    int t[101][101];
    int LCS(string X, string Y, int m, int n) {
    	// base case
    	if (m == 0 || n == 0) {
    		return 0;
        }
    	if (t[m][n] != -1) {
    		return t[m][n];
        }
        // choice diagram
    	if (X[m - 1] == Y[n - 1]) {    // when last character is same
    		t[m][n] = 1 + LCS(X, Y, m - 1, n - 1);    // count the number and decreament the both's string length // store the value in particular block 
        } 
        else {   // when last character is not same -> pick max
    		t[m][n] = max(LCS(X, Y, m - 1, n), LCS(X, Y, m, n - 1)); // one take full and another by leaving last char and vice versa // store the value in particular block 
        }
    	return t[m][n];
    }
    
    int shortestCommonSupersequence(string X, string Y, int m, int n) {
        memset(t, -1, sizeof(t));
        return m + n - LCS(X, Y, m, n);
    }
};



// Approach - 2 (Tabulation)
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
    
    int shortestCommonSupersequence(string X, string Y, int m, int n) {
        return m + n - LCS(X, Y, m, n);
    }
};
