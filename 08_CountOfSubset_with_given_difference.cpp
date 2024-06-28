// Question Link :- https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
// Partitions with Given Difference

// T.C = O(n*sum(arr))
// S.C = O(sum(arr))
class Solution {
public:
    int mod = 1e9+7;
    int CountSubsetsWithSum(vector<int>& arr, int n, int sum) {
    // 	int t[n + 1][sum + 1];
    vector<vector<int>> t(n + 1, vector<int>(sum + 1, 0));
    	// initialization 
    	for (int i = 0; i <= n; i++) {     // i -> size of the array
    		for (int j = 0; j <= sum; j++) {     // j -> target sum (subset sum)
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
    			if (arr[i - 1] <= j) {   // when element in the list is less then target sum 
    				t[i][j] = (t[i - 1][j - arr[i - 1]] + t[i - 1][j]) % mod; // either exclude or inxlude and add both of them to get final count 
    			} else {
    				t[i][j] = (t[i - 1][j]); // exclude when element in the list is greater then the sum 
    			}
    		}
    	}
    	return t[n][sum]; // finally return the last row and last column element 
    }

    int countPartitions(int n, int diff, vector<int>& arr) {
        int sumOfArray = 0;
    	for (int i = 0; i < n; i++) {
    		sumOfArray += arr[i]; 
    	}
    	if ((sumOfArray + diff) % 2 != 0) {
    		return 0;
    	}
    	return CountSubsetsWithSum(arr, n, (sumOfArray + diff) / 2);
    }
};