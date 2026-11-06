class Solution {
public:
    int solve(vector<int> &nums,int start,int end)
    {
        int prev1 = 0;
        int prev2 = 0;

        for(int i=start; i<=end; i++)
        {
            int result = max(prev2,prev1 + nums[i]);
            prev1 = prev2;
            prev2 = result;
        }
        return prev2;
    }
    int rob(vector<int>& nums) 
    {
        if(nums.size() == 1) return nums[0];
        
        int case1 = solve(nums,0,nums.size()-2);
        int case2 = solve(nums,1,nums.size()-1);

        return max(case1,case2);
    }
};
