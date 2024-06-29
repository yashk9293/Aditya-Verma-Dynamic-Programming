// Question Link :- https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
// Longest Repeating Subsequence

// Notes:- https://www.geeksforgeeks.org/longest-repeating-subsequence/

// T.C = O(n^2)
// S.C = O(n^2)

// Approach - 1 (LCS Memoization)
class Solution {
public:
    int LCS(string& X, string& Y, int n, int m, vector<vector<int>>&t) {
    	// base case
    	if (n == 0 || m == 0) {
    		return 0;
        }
    	if (t[n][m] != -1) {
    		return t[n][m];
        }
        // choice diagram
    	if (X[n - 1] == Y[m - 1] && n-1 != m-1) {    // when last character is same
    		t[n][m] = 1 + LCS(X, Y, n - 1, m - 1, t);    // count the number and decreament the both's string length // store the value in particular block 
        } 
        else {   // when last character is not same -> pick max
    		t[n][m] = max(LCS(X, Y, n - 1, m, t), LCS(X, Y, n, m - 1, t)); // one take full and another by leaving last char and vice versa // store the value in particular block 
        }
    	return t[n][m];
    }
    
	int LongestRepeatingSubsequence(string str) {
	    int n = str.size();
	    string str2(str.begin(), str.end());
		vector<vector<int>> t(n+1, vector<int>(n+1, -1));
		
		return LCS(str, str2, n, n, t);
	}
};





// Approach - 2 (Tabulation)
class Solution {
public:
    int LCS(string X, string Y, int n, int m, vector<vector<int>> dp) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i - 1] == Y[j - 1] && i != j) {    // when last character is same
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {      // when last character is not same -> pick max
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[n][m];
}
	int LongestRepeatingSubsequence(string &str){
	    int n = str.size();
	    string str2(str.begin(), str.end());
	    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	    
	    return LCS(str, str2, n, n, dp);
	}
};
