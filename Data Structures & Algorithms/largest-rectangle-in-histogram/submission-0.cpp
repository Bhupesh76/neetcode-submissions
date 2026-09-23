class Solution {
public:
    int largestRectangleArea(vector<int>& arr) 
    {
        stack<int> st;
        int area = 0;
        
        for(int i=0; i<=arr.size(); i++)
        {
            int currH = (i==arr.size()) ? 0 : arr[i];

            while(!st.empty() && arr[st.top()] > currH)
            {
                int H = arr[st.top()];
                st.pop();
                int W;

                if(st.empty())
                {
                    W = i;
                }
                else
                {
                    W = i - st.top() - 1;
                }

                area = max(area,H * W);
            }
            st.push(i);
        }
        return area;
    }
};
