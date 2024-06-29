// Question Link :- https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/
// Minimum Score Triangulation of Polygon

// T.C = O(N^3)
// S.C = O(N^2) 
class Solution {
public:
    int solve(vector<int>& arr,int i ,int j ,vector<vector<int>> &dp) {
        if(i>=j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int mini=1e9;
        for(int k=i; k<= j-1; k++) {
            int temp_ans = solve(arr,i,k,dp) + solve(arr,k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
            mini = min(mini, temp_ans);
        }
        return dp[i][j]=mini;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(values, 1, n-1, dp);
    }
};
