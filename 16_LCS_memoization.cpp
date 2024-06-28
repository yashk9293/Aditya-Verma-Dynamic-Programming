#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];

int LCS(string X, string Y, int n, int m) {
	// base case
	if (n == 0 || m == 0) {
		return 0;
    }
	if (t[n][m] != -1) {
		return t[n][m];
    }
    // choice diagram
	if (X[n - 1] == Y[m - 1]) {    // when last character is same
		t[n][m] = 1 + LCS(X, Y, n - 1, m - 1);    // count the number and decreament the both's string length // store the value in particular block 
    } 
    else {   // when last character is not same -> pick max
		t[n][m] = max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1)); // one take full and another by leaving last char and vice versa // store the value in particular block 
    }
	return t[n][m];
}

int main() {
	string X, Y;
    cin >> X >> Y;
	int n = X.length(), m = Y.length();

	memset(t, -1, sizeof(t)); // intialize the whole dp matrix with -1; // from memset we can initialise either -1 and zero;

	cout << LCS(X, Y, n, m) << endl;
	return 0;
}









// OR
static int dp[1001][1001];

class Solution {
    public: 
    int test(int x, int y, string &s1, string &s2) {
        if(x == 0 || y == 0) {
            return 0;
        }
        if(dp[x][y] != -1) {
            return dp[x][y];
        }
        if(s1[x-1] == s2[y-1]) {
            return dp[x][y] = 1 + test(x-1,y-1,s1,s2);
        }
        else {
            return dp[x][y] = max(test(x-1, y, s1, s2), test(x, y-1, s1, s2));
        }
    }
    
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        int p = test(x, y, s1, s2);
        return p;
    }
};