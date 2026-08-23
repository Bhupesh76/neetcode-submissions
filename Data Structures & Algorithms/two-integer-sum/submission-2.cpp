class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        unordered_map<int,int> mpp;

        for(int i=0; i<nums.size(); i++)
        {
            int temp = target-nums[i];

            if(mpp.find(temp) != mpp.end())
            {
                ans.push_back(mpp[temp]);
                ans.push_back(i);
                break;
            }
            mpp[nums[i]] = i;
        }
        return ans;
    }
};


