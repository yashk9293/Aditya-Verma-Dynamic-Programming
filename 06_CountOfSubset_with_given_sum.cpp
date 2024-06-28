// Question Link :- https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
// Perfect Sum Problem


// Brute Force
// generating all the possible subsets and then checking whether the subset has the required sum.


// Tabulation (Bottom-Up)
// T.C = O(sum*n)
// S.C = O(sum*n)
class Solution {
public:
    int mod = 1e9 + 7;
	int perfectSum(int arr[], int n, int sum) {
        // vector<vector<int>> t(n + 1, vector<int>(sum + 1, 0));
        int t[n + 1][sum + 1];
    	for (int i = 0; i<n+1; i++) {   // i -> size of array
    		for (int j = 0; j<sum+1; j++) {  // j -> target sum (subset sum)
    			if (i == 0) {
    				t[i][j] = 0;
    			}
    			if (j == 0) { 
    				t[i][j] = 1;
    			}
    		}
    	}

		for (int i = 1; i <n+1; i++) {
			for (int j = 0; j < sum+1; j++) {   // NOTE :- here j started from 0
				if (arr[i - 1] <= j) {   // when element in the list is less then target sum 
					t[i][j] = (t[i - 1][j - arr[i - 1]] + t[i - 1][j]) % mod;  // either exclude or inxlude and add both of them to get final count 
				} 
				else {
					t[i][j] = (t[i - 1][j]) % mod;  // exclude when element in the list is greater then the sum 
				}
			}
		}
		return t[n][sum];
	}
};
