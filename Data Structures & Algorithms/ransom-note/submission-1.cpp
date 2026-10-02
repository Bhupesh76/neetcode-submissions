class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char,int> mpp;
        for(int i=0; i<ransomNote.size(); i++)
        {
            mpp[ransomNote[i]]++;
        }
        int cnt = ransomNote.size();

        for(int i=0; i<magazine.size(); i++)
        {
            if(mpp.find(magazine[i]) != mpp.end() && mpp[magazine[i]] > 0)
            {
                mpp[magazine[i]]--;
                cnt--;
                if(cnt == 0) return true;
            }
        }
        return false;
    }
};