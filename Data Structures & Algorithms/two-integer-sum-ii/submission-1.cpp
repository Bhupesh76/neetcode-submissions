class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int i=0;
        int j=nums.size()-1;
        vector<int> ans;
        while(i<j)
        {
            int sum = nums[i] + nums[j];
            if(sum > target)
            {
                j--;
            }
            else if(sum < target)
            {
                i++;
            }
            else
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                i++;
                j--;
            }
        }
        return ans;
    }
};
