// Question Link :- https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// Matrix Chain Multiplication

// T.C = O(N^3)
// S.C = O(N^2)
class Solution {
public:
    int Solve(int arr[], int i, int j, vector<vector<int>>& t) {
    	if (i >= j) {
    		return 0;
    	}
    	if (t[i][j] != -1) {
    		return t[i][j]; 
    	}
    	int ans = INT_MAX;
    	for (int k = i; k <= j - 1; k++) {
    		int temp_ans = Solve(arr, i, k, t) + Solve(arr, k + 1, j, t) + arr[i - 1] * arr[k] * arr[j];
    		ans = min(ans, temp_ans);
    	}
    	return t[i][j] = ans;
    }

    int matrixMultiplication(int N, int arr[]) {
        vector<vector<int>> t(N, vector<int>(N, -1));
        return Solve(arr, 1, N-1, t);
    }
};
