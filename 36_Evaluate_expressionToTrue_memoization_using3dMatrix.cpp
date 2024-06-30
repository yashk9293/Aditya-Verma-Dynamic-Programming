// Question Link :- https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1
// Boolean Parenthesization

// T.C = O(N^3)
// S.C = O(N^2)

class Solution{
public:
    int Solve(string& s, int i, int j, bool isTrue, vector<vector<vector<long long>>>& t) {
    	if (i > j) {
            return 0;
        }
        if (i == j) {
    		if (isTrue) {
    			return s[i] == 'T';
    		} else {
    			return s[i] == 'F';
    		}
    	}
    	
    	if (t[i][j][isTrue] != -1) {
    	    return t[i][j][isTrue];
    	}
    
    	int ans = 0;
    	for (int k = i + 1; k <= j-1; k += 2) {     // k = k+2
    		long long l_T = Solve(s, i, k - 1, true, t);
    		long long l_F = Solve(s, i, k - 1, false, t);
    		long long r_T = Solve(s, k + 1, j, true, t);
    		long long r_F = Solve(s, k + 1, j, false, t);
    
    		if (s[k] == '|') {
    			if (isTrue == true) {
    				ans = (ans + (l_T * r_T)%1003 + (l_T * r_F)%1003 + (l_F * r_T)%1003)%1003;
    			} else {
    				ans = (ans + (l_F * r_F)%1003)%1003;
    			}
    		}
    		else if (s[k] == '&') {
    			if (isTrue == true) {
    				ans = (ans + (l_T * r_T)%1003)%1003;
    			} else {
    				ans = (ans + (l_T * r_F)%1003 + (l_F * r_T)%1003 + (l_F * r_F)%1003)%1003;
    			}
    		}
    		else if (s[k] == '^') {
    			if (isTrue == true) {
    				ans = (ans + (l_T * r_F)%1003 + (l_F * r_T)%1003)%1003;
    			} else {
    				ans = (ans + (l_T * r_T)%1003 + (l_F * r_F)%1003)%1003;
    			}
    		}
    	}
    	return t[i][j][isTrue] = ans;
    }
    
    int countWays(int n, string s){
        vector<vector<vector<long long>>> t(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
        int ans = Solve(s, 0, n-1, true, t);
        
        return ans;
    }
};






class Solution{
public:
    int t[205][205][2];
    int Solve(string s, int i, int j, bool isTrue) {
    	if (i > j) {
            return 0;
        }
        if (i == j) {
    		if (isTrue) {
    			return s[i] == 'T';
    		} else {
    			return s[i] == 'F';
    		}
    	}
    	
    	if (t[i][j][isTrue] != -1) {
    	    return t[i][j][isTrue];
    	}
    
    	int ans = 0;
    	for (int k = i + 1; k <= j-1; k += 2) {     // k = k+2
    		int l_T, l_F, r_T, r_F;
    		if(t[i][k-1][1] != -1){
                l_T = t[i][k-1][1];
            } else {
                l_T = Solve(s, i, k-1, 1);
                t[i][k-1][1] = l_T;
            }
            if(t[i][k-1][0] != -1){
                l_F = t[i][k-1][0];
            } else {
                l_F = Solve(s, i, k-1, 0);
                t[i][k-1][0] = l_F;
            }
            if(t[k+1][j][1] != -1){
                r_T = t[k+1][j][1];
            } else {
                r_T = Solve(s, k+1, j, 1);
                t[k+1][j][1] = r_T;
            }
            if(t[k+1][j][0] != -1){
                r_F = t[k+1][j][0];
            }
            else {
                r_F = Solve(s, k+1, j, 0);
                t[k+1][j][0] = r_F;
            }
    
    		if (s[k] == '|') {
    			if (isTrue == true) {
    				ans = (ans + (l_T * r_T) + (l_T * r_F) + (l_F * r_T))%1003;
    			} else {
    				ans = (ans + (l_F * r_F))%1003;
    			}
    		}
    		else if (s[k] == '&') {
    			if (isTrue == true) {
    				ans = (ans + (l_T * r_T))%1003;
    			} else {
    				ans = (ans + (l_T * r_F) + (l_F * r_T) + (l_F * r_F))%1003;
    			}
    		}
    		else if (s[k] == '^') {
    			if (isTrue == true) {
    				ans = (ans + (l_T * r_F) + (l_F * r_T))%1003;
    			} else {
    				ans = (ans + (l_T * r_T) + (l_F * r_F))%1003;
    			}
    		}
    	}
    	return t[i][j][isTrue] = ans;
    }
    
    int countWays(int n, string s){
        memset(t, -1, sizeof(t));
        int ans = Solve(s, 0, n-1, true);
        
        return ans;
    }
};
