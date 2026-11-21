class Solution {
public:
    void helper(vector<vector<int>> &ans,vector<int> &combin,vector<bool> &visited,vector<int> &nums)
    {
        if(combin.size() == nums.size()) 
        {
            ans.push_back(combin);
            return;
        }

        for(int i=0; i<nums.size(); i++)
        {
            if(visited[i]) continue;

            combin.push_back(nums[i]);
            visited[i] = true;

            helper(ans,combin,visited,nums);

            combin.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> combin;
        vector<bool> visited(nums.size(),false);
        helper(ans,combin,visited,nums);
        return ans;
    }
};
