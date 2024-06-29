// Question Link :- https://leetcode.com/problems/is-subsequence/
// Is Subsequence (follow up - Leetcode 792)

// Approach - 1 (proper solution for this ques)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == s.size();
    }
};



// Approach - 2 (Aditya Verma) [not necessary]
class Solution {
public:
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
                if (X[i - 1] == Y[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[n][m];
    }

    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        return LCS(s, t, n, m) == min(n, m);
    }
};



// X Y Z -> String 1
// A X B Y C Z E T -> String 2

// True
