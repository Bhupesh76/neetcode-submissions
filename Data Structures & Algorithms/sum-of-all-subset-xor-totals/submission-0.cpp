class Solution {
public:
    int helper(int i,vector<int>& nums,int ans)
    {
        if(i == nums.size()) return ans;
        int include = helper(i+1,nums,ans^nums[i]);
        int exclude = helper(i+1,nums,ans);
        return include + exclude;
    }
    int subsetXORSum(vector<int>& nums) 
    {
        return helper(0,nums,0);
    }
};