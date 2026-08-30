class MyHashMap {
public:
    vector<int> ans;

    MyHashMap() 
    {
        ans.resize(1000001, -1);
    }
    
    void put(int key, int value) 
    {
        ans[key] = value;
    }
    
    int get(int key) 
    {
        return ans[key];
    }
    
    void remove(int key) 
    {
        ans[key] = -1;
    }
};