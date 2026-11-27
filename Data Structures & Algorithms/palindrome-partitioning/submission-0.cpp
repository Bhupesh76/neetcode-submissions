class Solution {
public:
    bool ispal(string s)
    {
        string s1 = s;
        reverse(s1.begin(),s1.end());
        return s1==s;
    }
    void helper(vector<vector<string>> &ans,vector<string> &partition,string s)
    {
        if(s.size() == 0)
        {
            ans.push_back(partition);
        }

        for(int i=0; i<s.size(); i++)
        {
            string temp = s.substr(0,i+1);
            if(ispal(temp))
            {
                partition.push_back(temp);
                helper(ans,partition,s.substr(i+1));
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> partition;
        helper(ans,partition,s);
        return ans;
    }
};
