// Question Link :- https://leetcode.com/problems/longest-common-subsequence
// Longest Common Subsequence


// RECURSION (give TLE)
int longestCommonSubsequence(string a, string b, int n, int m) {

	// using recursion only
	if (n == 0 || m == 0) {
		return 0;
	}
	if (a[n - 1] == b[m - 1]) {
		return 1 + longestCommonSubsequence(a, b, n - 1, m - 1);
	}
	return max(longestCommonSubsequence(a, b, n - 1, m), longestCommonSubsequence(a, b, n, m - 1));

}




// MEMOIZATION (giving TLE to 1 last testcase)
class Solution {
public:
    int LCS(string text1, string text2, int n, int m, vector<vector<int>> &t) {
        if (n == 0 || m == 0) {
		    return 0;
		}
	    if (t[n][m] != -1) {
		    return t[n][m];
		}
	    if (text1[n - 1] == text2[m - 1]) {
		    t[n][m] = 1 + LCS(text1, text2, n - 1, m - 1, t);
		} else {
		    t[n][m] = max(LCS(text1, text2, n - 1, m, t), LCS(text1, text2, n, m - 1, t)); 
		}
	    return t[n][m];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> t(n+1, vector<int>(m+1, -1)); 

	    return LCS(text1, text2, n, m, t);
    }
};




// TABULATION :
// T.C = O(n*m)
// S.C = O(n*m)
class Solution {
public:
    int longestCommonSubsequence(string X, string Y) { 
        int n  = X.size();
        int m = Y.size();
        
        int dp[n + 1][m + 1];
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
};
