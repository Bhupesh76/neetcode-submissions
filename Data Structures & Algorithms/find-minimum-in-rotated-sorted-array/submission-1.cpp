class Solution {
public:
    int findMin(vector<int> &nums) 
    {
        int index = -1;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                index = i+1;
            }
        }
        return index == -1 ? nums[0]: nums[index];
    }
};
