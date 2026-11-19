class Solution {
public:
    void helper(vector<vector<int>> &ans,vector<int> &combin,vector<int> &arr,int target,int idx)
    {
        if(target == 0)
        {
            ans.push_back(combin);
            return; 
        }

        for(int i=idx; i<arr.size(); i++)
        {
            if(i > idx && arr[i] == arr[i-1]) continue;

            if(arr[i] > target) break;

            combin.push_back(arr[i]);

            helper(ans,combin,arr,target - arr[i],i+1);
            combin.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) 
    {
        vector<vector<int>> ans;
        vector<int> combin;
        sort(arr.begin(),arr.end());
        helper(ans,combin,arr,target,0);
        return ans;
    }
};
