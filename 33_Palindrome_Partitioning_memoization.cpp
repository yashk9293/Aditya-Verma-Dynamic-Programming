// Question Link :- https://leetcode.com/problems/palindrome-partitioning-ii/
// Palindrome Partitioning II

// Memoization (giving TLE)
class Solution {
public:
    bool isPalindrome(string X, int i, int j) { // function to check either a string is palindrome or not 
        while (i <= j) {
            if (X[i] != X[j]) {
                return false;
            }
            i++, j--;
        }
        return true;
    }

    int Solve(string X, int i, int j, vector<vector<int>>& t) {
        if (i >= j || isPalindrome(X, i, j)) {
            t[i][j] = 0;
            return 0;
        }
        if (t[i][j] != -1) {
            return t[i][j];
        }
        int ans = INT_MAX;
        for(int k = i; k <= j-1; k++) {
            int temp_ans = Solve(X, i, k, t) + Solve(X, k + 1, j, t) + 1;
            ans = min(ans, temp_ans);
        }
        return t[i][j] = ans;
    }

    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> t(n, vector<int>(n, -1));
        return Solve(s, 0, n-1, t);
    }
};
