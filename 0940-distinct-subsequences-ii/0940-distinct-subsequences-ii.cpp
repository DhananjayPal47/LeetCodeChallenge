class Solution {
    int MOD = 1e9 + 7;
    // private:
    //     int fun(string &s,int idx,char prev,map<pair<int,char>,int>&dp){
    //         if(idx>=s.size())return 1;
    //         if(dp.find({idx,prev})!=dp.end())return dp[{idx,prev}];
    //         int a=fun(s,idx+1,prev,dp)%MOD;
    //         if(s[idx]!=prev)a=(a%MOD+fun(s,idx+1,s[idx],dp)%MOD)%MOD;
    //         return dp[{idx,prev}]=a;
    //     }
public:
    int distinctSubseqII(string s) {
        int n = s.size();

        vector<int> curr(27, 0), next(27, 1);

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prev = 0; prev <= 26; prev++) {
                int a = next[prev];
                if (prev == 26 || s[idx] - 'a' != prev)
                    a = (a % MOD + next[s[idx] - 'a']) % MOD;
                curr[prev] = a;
            }
            next = curr;
        }

        int ans = curr[26];
        return (ans - 1 + MOD) % MOD;
    }
};