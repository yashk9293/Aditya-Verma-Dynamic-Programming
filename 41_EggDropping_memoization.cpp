// Question Link :- https://leetcode.com/problems/super-egg-drop/
// Question Link :- https://www.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
// Super Egg Drop

// Passed in GfG but giving TLE in LeetCode

// T.C = O(egg * floor^2) ~ O(n * k^2)
// S.C = O(egg * floor) ~ O(n * k)
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
    	for (int k = 1; k <= floors; k++) {
    		int temp_ans = 1 + max(Solve(eggs - 1, k - 1, t), Solve(eggs, floors - k, t)); // once egg break means decrement both floor and egg another agg did not break means check egg dropping from above 
    		mn = min(mn, temp_ans);
    	}
    	return t[eggs][floors] = mn;
    }

    int superEggDrop(int eggs, int floors) {
        vector<vector<int>> t(eggs+1, vector<int> (floors+1, -1));
        return Solve(eggs, floors, t);
    }
};




// Memoization Optimized (TLE in LeetCode)
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
    	for (int k = 1; k <= floors; k++) {
            int top, bottom;
            if (t[eggs - 1][k - 1] != -1) {
                top = t[eggs - 1][k - 1];
            } else {
                top = Solve(eggs - 1, k - 1, t);
                t[eggs - 1][k - 1] = top;
            }

            if (t[eggs][floors - k] != -1) {
                bottom = t[eggs][floors - k];
            } else {
                bottom = Solve(eggs, floors - k, t);
                t[eggs][floors - k] = bottom;
            }

    		int temp_ans = 1 + max(top, bottom);
    		mn = min(mn, temp_ans);
    	}
    	return t[eggs][floors] = mn;
    }

    int superEggDrop(int eggs, int floors) {
        vector<vector<int>> t(eggs+1, vector<int> (floors+1, -1));
        return Solve(eggs, floors, t);
    }
};
