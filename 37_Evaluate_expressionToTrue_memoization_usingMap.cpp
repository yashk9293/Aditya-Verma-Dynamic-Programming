// Question Link :- https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1
// Boolean Parenthesization

// (giving TLE)
class Solution{
public:
    unordered_map<string, int> mp;
    int Solve(string& s, int i, int j, bool isTrue) {
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
    	string key = to_string(i) + " " + to_string(j) + " " + (isTrue ? "T" : "F");
    	if (mp.find(key) != mp.end()) {
    		return mp[key];
    	}
    
    	int ans = 0;
    	for (int k = i + 1; k <= j-1; k += 2) {     // k = k+2
    	    int l_T = Solve(s, i, k - 1, true);
    		int l_F = Solve(s, i, k - 1, false);
    		int r_T = Solve(s, k + 1, j, true);
    		int r_F = Solve(s, k + 1, j, false);
    
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
    	return mp[key] = (ans%1003);
    }
    
    int countWays(int n, string s){
        mp.clear();
        int ans = Solve(s, 0, n-1, true);
        
        return ans;
    }
};
