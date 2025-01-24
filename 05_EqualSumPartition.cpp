// Question Link :- https://leetcode.com/problems/partition-equal-subset-sum/
// Partition Equal Subset Sum


// Tabulation
// T.C = O(sum*n)
// S.C = O(sum)
class Solution {
public:
    bool isSubsetPossible(vector<int>& arr, int n, int sum) {
    	bool t[n + 1][sum + 1]; // DP - matrix
    	// initialization
    	for (int i = 0; i<n+1; i++) {   // i -> size of array
    		for (int j = 0; j<sum+1; j++) {  // j -> target sum (subset sum)
    			// when array(i) is empty than there is no meaning of sum of elements so return false
    			if (i == 0) {
    				t[i][j] = false;
    			}
    			// when sum(j) is zero and there is always a chance of empty subset so return it as true;
    			if (j == 0) { 
    				t[i][j] = true;
    			}
    		}
    	}
    	for (int i = 1; i <n+1; i++) {
    		for (int j = 1; j <sum+1; j++) {
    			if (arr[i - 1] <= j) {
                    // after taking and element substract from the (sum) i.e -> in {3,8} 3 is taken then we want 11-3=8in the array 
    				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j]; // either take or(||) do not take 
    			} else {// if sum is less than array size just leave and increment 
    				t[i][j] = t[i - 1][j];
				}
    		}
    	}
    	return t[n][sum]; // at last return T/F
    }

    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
    	for (int i = 0; i < n; i++) {
    		sum += arr[i];
    	}
    	if (sum % 2 != 0) { // if sum is odd --> not possible to make equal partitions
    		return false;
    	}
    	return isSubsetPossible(arr, n, sum / 2);
    }
};



// Memoization
// T.C = O(sum*n)
// S.C = O(sum*n)
class Solution {
public:
    bool solve(vector<int>& nums, int n, int target, vector<vector<bool>>& dp) {
        if(target == 0) {
            return true;
        }
        if(n == 0) {
            return false;
        }
        if(dp[n][target] != false) {
            return dp[n][target];
        }
        if(nums[n-1] <= target) {
            dp[n][target] = solve(nums, n-1, target - nums[n-1], dp) || solve(nums, n-1, target, dp);
        } else {
            dp[n][target] = solve(nums, n-1, target, dp);
        }
        return dp[n][target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        if(sum % 2 != 0) {
            return false;
        }

        int target = sum/2;

        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        return solve(nums, n, target, dp);
    }
};
