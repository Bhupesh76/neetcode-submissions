class Solution {
public:
    void helper(int n,int cc,int oc, vector<string> &v,string s)
    {
        if(oc == n && cc == n)
        {
            v.push_back(s);
        }

        if(oc < n)
        {
            helper(n,cc,oc+1,v,s+"(");
        }

        if(cc < oc)
        {
            helper(n,cc+1,oc,v,s+")");
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> v;
        helper(n,0,0,v,"");
        return v;
    }
};
