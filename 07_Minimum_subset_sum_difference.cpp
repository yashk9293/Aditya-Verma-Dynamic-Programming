// Question Link :- https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
// Minimum sum partition

// Note :- 0 < arr[i] <= 10^5

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