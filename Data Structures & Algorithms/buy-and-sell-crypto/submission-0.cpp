class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit = 0;
        int minprice = prices[0];

        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i] < minprice)
            {
                minprice = prices[i];
            }
            else
            {
                profit = max(profit,prices[i]-minprice);
            }
        }
        return profit;
    }
};
