// Question Link :- https://leetcode.com/problems/super-egg-drop/
// Super Egg Drop

// T.C = O((floor * eggs) * log(floor)) ~ O((n*k) logn)
// S.C = O(floor * eggs) ~ O(n*k)
class Solution {
public:
    int Solve(int eggs, int floors, vector<vector<int>>& t) {
    	if (t[eggs][floors] != -1) {
    		return t[eggs][floors];
    	}
    	if (eggs == 0) {
    		return 0;
    	}
    	if (eggs == 1 || floors == 0 || floors == 1) {
    		return floors;
	    }
    
    	int mn = INT_MAX;
        int low = 0, high = floors, temp = 0;
    	while(low <= high){
            int mid = (low + high)/2;
            
            /* representing both the choices with memo
            First one, if the egg will break, no. of eggs will decreased and we have to
            down from that floor.
            Second one, if the egg will not break, no. of eggs will not decreased and we
            have to go above form that floor. */
            
            int left = Solve(eggs-1, mid-1, t);
            int right = Solve(eggs, floors-mid, t);
            
            temp = 1 + max(left, right);
            
            //since we need more temp value in worst case, so need to go above
            if(left < right) {
                low = mid+1;
            } else {
                high = mid-1;     // move to the downward
            }
            mn = min(mn, temp);  // minimum number of attempts
        }
    	return t[eggs][floors] = mn;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> t(k+1, vector<int> (n+1, -1));
        return Solve(k, n, t);
    }
};
