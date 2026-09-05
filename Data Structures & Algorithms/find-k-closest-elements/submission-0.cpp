class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        vector<int> ans;
        vector<pair<int,int>> v;

        for(int i = 0; i < arr.size(); i++)
        {
            v.push_back({arr[i], abs(x - arr[i])});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b)
        {
            if(a.second == b.second)
                return a.first < b.first;

            return a.second < b.second;
        });

        for(int i = 0; i < k; i++)
        {
            ans.push_back(v[i].first);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};