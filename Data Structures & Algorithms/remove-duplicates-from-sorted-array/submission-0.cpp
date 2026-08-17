class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            if(find(ans.begin(),ans.end(),nums[i]) == ans.end())
            {
                ans.push_back(nums[i]);
            }
        }
        for(int i=0; i<ans.size(); i++)
        {
            nums[i] = ans[i];
        }

        return ans.size();
    }
};