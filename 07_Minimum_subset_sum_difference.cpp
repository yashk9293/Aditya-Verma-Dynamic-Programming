// Question Link :- https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
// Minimum sum partition

// Note :- 0 < arr[i] <= 10^5


// Tabulation
// T.C = O(n*sum)
// S.C = O(n*sum)
class Solution {
public:
    vector<int> isSubsetPoss(int arr[], int n, int sum) {
    	bool t[n + 1][sum + 1];
    	// initialization
    	for (int i = 0; i <= n; i++) {
    		for (int j = 0; j <= sum; j++) {
    			if (i == 0) {
    				t[i][j] = false;
    			}
    			if (j == 0) {
    				t[i][j] = true;
    			}
    		}
    	}
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= sum; j++) {
    			if (arr[i - 1] <= j) {
    				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j]; // include or exclude
    			} else {
    				t[i][j] = t[i - 1][j];  // exclude
    			}
    		}
    	}
    	vector<int> v;   // contains all subset sums possible with n elements 
    	for (int j = 0; j <= sum; j++) {
    		if (t[n][j] == true) {
    			v.push_back(j); {
    			}
    		}
    	}
    	return v;
    }
    
	int minDifference(int arr[], int n)  { 
	    int range = 0;
        for(int i=0; i<n; i++) {
            range += arr[i];
        }
        vector<int> v = isSubsetPoss(arr, n, range);
        int mn = INT_MAX;
        for(int i=0; i< v.size(); i++) {
            mn = min(mn, abs(range - 2*v[i]));
        }
        return mn;
	} 
};



// Memoization
// T.C = O(n*sum)
// S.C = O(n*sum)
class Solution {
  public:
    int solve(vector<int>& arr, int n, int sum, int currSum, vector<vector<int>>& dp) {
        int ans=INT_MAX;
        if(n == 0) {
            ans = min(ans, abs(sum - 2*currSum));
            return ans;
        }
        if(n < 0) {
            return 0;
        }
        
        if(dp[n][currSum] != -1) {
            return dp[n][currSum];
        }
        
        int take = 0, skip = 0;
        take = solve(arr, n-1, sum, currSum + arr[n-1], dp);
        skip = solve(arr, n-1, sum, currSum, dp);
        
        return dp[n][currSum] = min(take, skip);
    }

    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
	    for(int i=0; i<n; i++){
	        sum += arr[i];
	    }
	    vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
	    return solve(arr, n, sum, 0, dp);
    }
};
