// Question Link :- https://leetcode.com/problems/palindrome-partitioning-ii/
// Palindrome Partitioning II

// Memoization Optimized (striver)
// T.C = O(N^2) There are a total of N states and inside each state, a loop of size N(apparently) is running.
// S>C = O(N) ->[dp array] + Auxiliary stack space O(N)
class Solution {
public:
    bool isPalindrome(string& X, int i, int j) {  // Note:- pass string by reference, to avoid TLE
        while (i <= j) {
            if (X[i] != X[j]) {
                return false;
            }
            i++, j--;
        }
        return true;
    }

    int Solve(string &str, int i, int j, vector<int> &t) {
        // Base case: If we've reached the end of the string.
        if (i >= j) {
            return 0;
        }
        if (t[i] != -1) {
            return t[i];
        }
        int ans = INT_MAX;
        // Consider all possible substrings starting from the current index.
        for (int k = i; k <= j-1; k++) {
            if (isPalindrome(str, i, k)) {
                // If the substring is a palindrome, calculate the cost and minimize it.
                int temp_ans = 1 + Solve(str, k + 1, j, t);
                ans = min(ans, temp_ans);
            }
        }
        return t[i] = ans;
    }

    int minCut(string s) {
        int n = s.length();
        vector<int> t(n, -1);
        return Solve(s, 0, n, t) - 1;
    }
};
