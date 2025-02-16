// Question Link :- https://leetcode.com/problems/coin-change/description/
// Coin Change I

/*
Brute Force
arr = [9, 6, 5, 1]
target = 11
A Greedy solution will be to take the highest denomination coin first, so we will take an item on 
index 0, with a value of 9. Now the remaining target sum will be 2. Therefore we can only consider 
coins with a value of 1. We will take 2 coins of value 1 to meet the target. So a greedy solution 
gives us the answer 3 {9,1,1}.

Now we can clearly see that a non-greedy solution of taking 2 coins valued 6 and 5 will give us a 
better option. So we can say that the greedy solution doesn’t work for this problem. 

As the greedy approach doesn’t work, we will try to generate all possible combinations using 
recursion and select the combination which gives us the minimum number of coins.

*/



// Approach - 1(Recursion) [Giving TLE]
// T.C = O(n^amount) where n = length of coins array
// S.C = O(n)




// Approach - 3(Memoization - Top Down)
// T.C = O(n*amount)
// S.C = O(n*amount)
class Solution {
public:
    int solve(vector<int>& coins, int amount, int n, vector<vector<int>>& dp) {
        if (amount == 0) {
            return 0;
        }
        if (n <= 0) {
            return 1e9;
        }
        if(dp[n][amount] != -1){
            return dp[n][amount];
        }
        // take the current coin
        int take = 1e9, skip = 0;
        if (coins[n-1] <= amount) {
           take = 1 + solve(coins, amount - coins[n-1], n, dp);
        }
        // skip the current coin
       skip= solve(coins, amount, n-1, dp);

       return dp[n][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp (n+1, vector<int>(amount+1, -1));
        int ans = solve(coins, amount, n, dp);
        if(ans == 1e9) {
            return -1;
        } else {
            return ans;
        }
    }
};





// Approach - 3(Tabulation - Bottom Up)
// T.C = O(n*amount)
// S.C = O(n*amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int t[n+1][amount+1];
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=amount; j++) {
                if(j==0) {
                    t[i][j] = 0;
                }
                if(i==0) {
                    t[i][j] = INT_MAX-1;
                }
            }
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=amount; j++) {
                if(coins[i-1] <= j) {
                    t[i][j] = min(1 + t[i][j-coins[i-1]], t[i-1][j]);
                }
                else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        if(t[n][amount] == INT_MAX-1) {
            return -1;
        }
        else {
            return t[n][amount];
        }
    }
};
