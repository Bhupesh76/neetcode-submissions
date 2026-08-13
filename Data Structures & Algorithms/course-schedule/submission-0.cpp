class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        vector<int> topo;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto it : pre)
        {
            adj[it[0]].push_back(it[1]);
        }
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
            if(indegree[i] == 0)
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
        return topo.size() == n;
    }
};
