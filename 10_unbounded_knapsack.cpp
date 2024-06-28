// Question Link :- https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
// Knapsack with Duplicate Items (Unbounded Knapsack)

// T.C = O(n*W)
// S.C = O(W)
class Solution {
public:
    int knapSack(int n, int W, int val[], int wt[]) {
        int t[n + 1][W + 1];
    	for (int i = 0; i <= n; i++) {
    		for (int j = 0; j <= W; j++) {
    			if (i == 0 || j == 0) { // base case
    				t[i][j] = 0;
				}
    			else if (wt[i - 1] <= j) { // current wt can fit in bag
    				t[i][j] = max(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);
    			}
    			else if (wt[i - 1] > j) { // current wt doesn't fit in bag
    				t[i][j] = t[i - 1][j];
				}
    		}
    	}
    	return t[n][W];
    }
};