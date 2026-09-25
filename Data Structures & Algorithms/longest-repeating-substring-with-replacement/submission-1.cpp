class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        vector<int> freq(26,0);

        int l = 0;
        int ans = 0;

        for(int r = 0; r<s.size(); r++)
        {
            freq[s[r]-'A']++;

            int maxf = max(freq[s[r]-'A'],maxf);

            int ws = r-l+1;

            int replace = ws - maxf;

            while(replace > k)
            {
                freq[s[l]-'A']--;
                l++;
                ws = r-l+1;
                replace = ws-maxf;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};
