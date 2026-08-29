class MyHashSet {
public:
    vector<int> ans;
    MyHashSet() 
    {
    }
    void add(int key) 
    {
        if(!contains(key)) ans.push_back(key);
    }
    
    void remove(int key) 
    {
        for(int i=0; i<ans.size(); i++)
        {
            if(key == ans[i])
            {
                ans.erase(ans.begin()+i);
            }
        }
    }
    
    bool contains(int key) 
    {
        for(int i=0; i<ans.size(); i++)
        {
            if(key == ans[i]) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */