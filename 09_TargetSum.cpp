// Question Link :- https://leetcode.com/problems/target-sum/
// Target Sum

// T.C = O(n*sum(arr))
// S.C = O(sum(arr))
class Solution {
public:
    int CountSubsetsWithSum(vector<int>& arr, int n, int sum) {
	    int t[n + 1][sum + 1];
	    for (int i = 0; i <= n; i++) {
		    for (int j = 0; j <= sum; j++) {
			    if (i == 0) {
				    t[i][j] = 0;
                }
			    if (j == 0) {
				    t[i][j] = 1;
                }
		    }
	    }
	    for (int i = 1; i <= n; i++) {
		    for (int j = 0; j <= sum; j++) {
			    if (arr[i - 1] <= j) {
				    t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j]; 
                } else {
				    t[i][j] = t[i - 1][j];
                }
		    }
	    }
	    return t[n][sum]; 
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        target = abs(target);
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        if(sum<target || (sum + target)%2 != 0) {
            return 0;
        }
        return CountSubsetsWithSum(nums, n, (sum + target)/2);
    }
};