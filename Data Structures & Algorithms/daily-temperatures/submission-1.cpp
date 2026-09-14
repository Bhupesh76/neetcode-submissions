class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) 
    {
        int n = temp.size();
        vector<int> res(n,0);

        stack<int> st;

        for(int i=0; i<temp.size(); i++)
        {
            while(!st.empty() && temp[i] > temp[st.top()])
            {
                int prev = st.top();
                st.pop();
                res[prev] = i-prev;
            }
            st.push(i);
        }

        return res;
    }
};
