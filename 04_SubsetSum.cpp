// Question Link :- https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// Subset Sum Problem

// Tabulation
// T.C = O(sum*n)
// S.C = O(sum*n)
class Solution {
public:
    bool isSubsetSum(vector<int>arr, int sum) {
        int n = arr.size();
        bool t[n + 1][sum + 1];
    	// initialization
    	for (int i=0; i<n+1; i++) {          // i -> size of the array
    		for (int j=0; j<sum+1; j++) {    // j -> target sum (subset sum)
    			if (i == 0) {
    				t[i][j] = false;
    			}
    			if (j == 0) {
    				t[i][j] = true;
    			}
    		}
    	}
    	for (int i = 1; i<n+1; i++) {
    		for (int j = 1; j<sum+1; j++) {
    			if (arr[i - 1] <= j) {   // if element of arr is smaller than the target sum
    				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j]; // either take or(||) do not take 
    			} 
				else {  // if element of arr is greater than the target sum
    				t[i][j] = t[i - 1][j];
    			}
    		}
    	}
    	return t[n][sum]; // at last return T/F
    }
};




// Memoization
// T.C = O(sum*n)
// S.C = O(sum*n)
class Solution {
  public:
    bool solve(vector<int>& arr, int target, int n, vector<vector<bool>>& dp) {
        if(target == 0) {
            return true;
        }
        if(n == 0) {
            return false;
        }
        if(dp[n][target] != false) {
            return dp[n][target];
        }
        if(arr[n-1] <= target) {
            dp[n][target] = solve(arr, target-arr[n-1], n-1, dp) || solve(arr, target, n-1, dp);
        } else {
            dp[n][target] = solve(arr, target, n-1, dp);
        }
        return dp[n][target];
    }

    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        return solve(arr, target, n, dp);
    }
};
