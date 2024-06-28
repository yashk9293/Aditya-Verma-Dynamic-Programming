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
class Solution {
public:
    int solve(vector<int>& coins, int amount) {
        if(amount == 0) {
            return 0;
        }
        if(amount < 0) {
            return INT_MAX;
        }
        int minCoins = INT_MAX;
        for(auto i: coins) {
            int res = solve(coins, amount-i);
            if(res != INT_MAX) {
                minCoins = min(minCoins, res+1);
            }
        }
        return minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);
        if(ans == INT_MAX) {
            return -1;
        } else {
            return ans;
        }
    }
};





// Approach - 3(Memoization - Top Down)
// T.C = O(n*amount)
// S.C = O(n*amount)
class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        if(amount == 0) {  // amount has reached 0
            return 0;
        }
        if(amount < 0) {   // the denomination choice is wrong
            return INT_MAX;
        }
        if(dp[amount] != -1) {
            return dp[amount];
        }
        int minCoins = INT_MAX;
        for(auto i: coins) {
            int res = solve(coins, amount-i, dp);
            if(res != INT_MAX) {
                minCoins = min(minCoins, res+1);
            }
        }
        return dp[amount] = minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans = solve(coins, amount, dp);
        if(ans == INT_MAX) {
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
                if(i==1) {
                    if(j % coins[0] == 0) {
                        t[i][j] = j/coins[0];
                    } else {
                        t[i][j] = INT_MAX-1;
                    }
                }
            }
        }
        for(int i=2; i<=n; i++) {
            for(int j=1; j<=amount; j++) {
                if(coins[i-1] <= j) {
                    t[i][j] = min(t[i-1][j], 1+t[i][j-coins[i-1]]);
                }
                else if(coins[i-1] > j) {
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