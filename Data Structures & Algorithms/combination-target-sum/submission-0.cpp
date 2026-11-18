class Solution {
public:
    set<vector<int>> s;
    void helper(vector<int> &nums,vector<vector<int>> &ans,vector<int> &combin,int tar,int idx)
    {
        if(idx == nums.size() || tar < 0) return;

        if(tar == 0)
        {
            if(s.find(combin) == s.end())
            {
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }
        combin.push_back(nums[idx]);
        helper(nums,ans,combin,tar-nums[idx],idx+1);
        helper(nums,ans,combin,tar-nums[idx],idx);
        combin.pop_back();
        helper(nums,ans,combin,tar,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> ans;
        vector<int> combin;
        helper(nums,ans,combin,target,0);
        return ans;
    }
};
