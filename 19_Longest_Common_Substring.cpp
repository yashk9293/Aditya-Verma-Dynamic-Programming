// Question Link :- https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
// Longest Common Substring

// Notes:- https://www.geeksforgeeks.org/longest-common-substring-dp-29/

// T.C = O(n*m)
// S.C = O(n*m)

// IMPORTANT - in this question the final answer could be anywhere in the matrix, not always in
//             t[n][m] last row col. So that's why we ar using ans variable to stroe the max value.

// Approach - 1(using global 'ans' variable)
class Solution{
    public:
    int longestCommonSubstr (string S1, string S2, int n, int m) {
        int ans = 0;
        int t[n+1][m+1];
        // base condition
        for(int i=0; i<n+1; i++) {
            for(int j=0; j<m+1; j++) {
                if(i==0 || j==0) {
                  t[i][j] = 0;
                }
            }
        }
        // choice diagram
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(S1[i-1] == S2[j-1]){
                  t[i][j] = 1 + t[i-1][j-1];
                  ans = max(ans, t[i][j]);   // modification
                }
                else {
                   t[i][j] = 0;
                }
            }
        }
        return ans;
    }
};




// Approach - 2
class Solution{
    public:
    int longestCommonSubstr (string S1, string S2, int n, int m) {
        int t[n+1][m+1];
        // base condition
        for(int i=0; i<n+1; i++) {
            for(int j=0; j<m+1; j++) {
                if(i==0 || j==0) {
                  t[i][j] = 0;
                }
            }
        }
        // choice diagram
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(S1[i-1] == S2[j-1]){
                  t[i][j] = 1 + t[i-1][j-1];
                }
                else {
                   t[i][j] = 0;
                }
            }
        }
        int ans = INT_MIN;
    	for (int i = 0; i <= n; i++) {
    		for (int j = 0; j <= m; j++) {
    			ans = max(ans, t[i][j]);
    		}
    	}
    	return ans;
    }
};

