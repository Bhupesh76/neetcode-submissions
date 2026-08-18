class Solution {
public:
    int ladderLength(string beginword, string endword, vector<string>& wordlist) 
    {
        if (beginword.size() != endword.size()) return 0;
        if (beginword == endword) return 0;
        queue<pair<string,int>> q;
        q.push({beginword,1});
        unordered_set<string> st(wordlist.begin(),wordlist.end());
        st.erase(beginword);

        while(!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endword) return steps;
            for(int i=0; i<word.size(); i++)
            {
                char og = word[i];
                for(char ch='a'; ch<='z'; ch++)
                {
                    word[i] = ch;
                    if(st.find(word) != st.end())
                    {
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i] = og;
            }
        }
        return 0;
    }
};
