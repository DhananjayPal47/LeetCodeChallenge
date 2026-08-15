class Solution {
    int MOD=1e9+7;
private:
    int fun(string &s,int idx,char prev,map<pair<int,char>,int>&dp){
        if(idx>=s.size())return 1;
        if(dp.find({idx,prev})!=dp.end())return dp[{idx,prev}];
        int a=fun(s,idx+1,prev,dp)%MOD;
        if(s[idx]!=prev)a=(a%MOD+fun(s,idx+1,s[idx],dp)%MOD)%MOD;
        return dp[{idx,prev}]=a;
    }
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        map<pair<int,char>,int>dp;
        int ans=fun(s,0,'#',dp);
        return (ans-1+MOD)%MOD;
        
    }
};