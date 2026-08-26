class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int l = 0;
        int r = 0;
        int ans = 0;
        unordered_set<char> st;
        while(r<s.size())
        {
            if(st.find(s[r]) == st.end()) 
            {
                st.insert(s[r]);
                r++;
                ans = max(ans,r-l);
            }
            else
            {
                st.erase(s[l]);
                l++;
            }
        }
        return ans;
    }
};
