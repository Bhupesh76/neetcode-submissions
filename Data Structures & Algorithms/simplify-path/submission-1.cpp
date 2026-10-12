class Solution {
public:
    string simplifyPath(string path) 
    {
        stringstream ss(path);
        string dir;
        stack<string> st;

        while(getline(ss,dir,'/'))
        {
            if(dir == "" || dir == ".")
            {
                continue;
            }

            if(dir == "..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(dir);
            }
        }

        string ans = "";

        while(!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};