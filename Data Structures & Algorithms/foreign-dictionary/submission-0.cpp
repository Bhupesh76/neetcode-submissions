class Solution {
public:
    vector<int> toposort(int n,vector<vector<int>> &adj,vector<int> &present)
    {
        vector<int> indegree(26,0);
        vector<int> topo;

        for(int i=0; i<n; i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(indegree[i] == 0 && present[i])
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return topo;
    }
    string foreignDictionary(vector<string>& words) 
    {
        vector<vector<int>> adj(26);
        vector<int> present(26,0);
        int uc = 0;
        for(auto word:words)
        {
            for(auto ch : word)
            {
                if(!present[ch-'a'])
                {
                    present[ch-'a'] = 1;
                    uc++;
                }
            }
        }

        for(int i=0; i<words.size()-1; i++)
        {
            string str1 = words[i];
            string str2 = words[i+1];
            int len = min(str1.size(),str2.size());
            bool fd = false;
            for(int ptr=0; ptr<len; ptr++)
            {
                if(str1[ptr] != str2[ptr])
                {
                    int u = str1[ptr] - 'a';
                    int v = str2[ptr] - 'a';
                    adj[u].push_back(v);
                    fd = true;
                    break;
                }       
            }
            if(!fd && str1.size() > str2.size()) return "";
        }
        vector<int> topo = toposort(26,adj,present);
        if(topo.size()!= uc) return "";
        string ans = "";
        for(auto it:topo)
        {
            ans += char(it + 'a');
        }
        return ans;
    }
};
