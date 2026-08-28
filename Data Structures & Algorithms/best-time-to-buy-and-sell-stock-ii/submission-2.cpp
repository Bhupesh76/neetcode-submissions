class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int ans = 0;
        int min = prices[0];
        int i = 0;
        while(i<prices.size()-1)
        {
            if(prices[i+1] >= prices[i])
            {
                i++;
            }
            else
            {
                ans += prices[i] - min;
                min = prices[i+1];
                i++;
            }
        }
        ans += prices[i] - min;
        return ans;
    }
};