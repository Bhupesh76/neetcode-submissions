class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mpp;
    int cnt = 0;
    TimeMap() 
    {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        mpp[key].push_back({timestamp,value});

    }
    
    string get(string key, int timestamp) 
    {
        if(mpp.find(key) == mpp.end()) return "";

        const vector<pair<int,string>> &arr = mpp[key];
        string ans = "";
        int l = 0;  
        int h = arr.size()-1;

        while(l<=h)
        {
            int mid = l + (h-l)/2;

            if(arr[mid].first <= timestamp)
            {
                ans = arr[mid].second;
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }
        }
        return ans;
    }
};
