// Question Link :- https://leetcode.com/problems/scramble-string/
// Scramble String


// T.C = O(N^4)
// S.C = O(N^3)
class Solution {
public:
    unordered_map<string, bool> mp;
    bool Solve(string X, string Y) {
        string key = X + " " + Y;
        if (mp.find(key) != mp.end()) { // if we did not found the and travesed upto end of the map 
            return mp[key];
        }
        if (X.compare(Y) == 0) {
            mp[key] = true;
            return true;
        }
        if (X.length() <= 1) {
            mp[key] = false;
            return false;
        }

        int n = X.length();
        bool flag = false;
        for (int i = 1; i <= n - 1; i++) {
            if ((Solve(X.substr(0, i), Y.substr(n - i, i)) && Solve(X.substr(i), Y.substr(0, n - i))) ||
                    (Solve(X.substr(0, i), Y.substr(0, i)) && Solve(X.substr(i), Y.substr(i)))) {
                flag = true;
                break;
            }
        }
        return mp[key] = flag; // store in table for further reference 
    }

    bool isScramble(string s1, string s2) {
        mp.clear();
        return Solve(s1, s2);
    }
};
