// Question Link :- https://www.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1
// Minimum number of deletions to make string Palindrome

// Question Link :- https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Minimum Insertion Steps to Make a String Palindrome


// Brute Force (Recursion)
// T.C = O(2^n)
// S.C = O(n)


// Better Solution (Tabulation)
// T.C = O(n^2)
// S.C = O(n^2)
int LCS(string X, string Y, int n, int m) {
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i - 1] == Y[j - 1]) {    // when last character is same
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {    // when last character is not same -> pick max
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[n][m];
}

int minDeletions(string str, int n) { 
    string rev_str = str;
	reverse(rev_str.begin(), rev_str.end());
	
	return n - LCS(str, rev_str, n, n);   // n - Longest palindromic subsequence length
}
