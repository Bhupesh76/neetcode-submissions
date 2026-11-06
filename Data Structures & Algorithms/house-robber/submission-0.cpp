class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size() == 1) return nums[0];
        int prev1 = nums[0];
        int prev2 = max(nums[0],nums[1]);
        int result = prev2;
        for(int i=2; i<nums.size(); i++)
        {
            result = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = result;
        }
        return result;
    }
};
