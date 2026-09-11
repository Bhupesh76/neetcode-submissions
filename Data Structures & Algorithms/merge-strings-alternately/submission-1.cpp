class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        string ans = "";
        int n = min(word1.size(),word2.size());

        int i = 0;
        while(i<n)
        {
            ans += word1[i];
            ans += word2[i];
            i++;
        }

        if(i<word1.size())
        {
            while(i<word1.size())
            {
                ans += word1[i];
                i++;
            }
        }

        if(i<word2.size())
        {
            while(i<word2.size())
            {
                ans += word2[i];
                i++;
            }
        }
        return ans;
    }
};