class Solution {
public:
    vector<int> dp;
    bool help(int i,string &s,set<string> &st)
    {
        if(i == s.size()) return 1;
        if(dp[i]!= -1) return dp[i];
        string temp = "";
        for(int j=i; j<s.size(); j++)
        {
            temp += s[j];
            if(st.find(temp) != st.end())
            {
                if(help(j+1,s,st)) return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        set<string> st;
        for(auto a:wordDict) st.insert(a);
        dp.assign(s.size(),-1);
        return help(0,s,st);
    }
};
