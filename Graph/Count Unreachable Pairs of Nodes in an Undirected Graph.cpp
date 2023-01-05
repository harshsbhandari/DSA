https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

// Good counting mechanism used below [(O)n(sq) -> (O)n]
void bfs(int start, vector<int>adj[], vector<int>&vis, int& count){
        queue<int>q;

        q.push(start);
        vis[start] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto i : adj[node]){
                if(!vis[i]){
                    q.push(i);
                    vis[i] = 1;
                    count++;
                }
            }
        }

    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];

        for(auto i : edges){
            int u = i[0], v = i[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        vector<int>vis(n, 0);
        vector<int>v;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int count = 1;
                bfs(i, adj, vis, count);
                v.push_back(count);
            }
        }
      
        // below is the simple counting of the combinations
        int m = v.size();
        long long ans = 0;
        vector<int>suff(m);

        suff[m-1] = v[m-1];
        
        for(int i = m-2; i >= 0; i--)
            suff[i] = suff[i+1]+v[i]; 
        
        for(int i = 0; i < m-1; i++)
            ans = ans+((long long)v[i] * (long long)suff[i+1]);

        return ans;
    }
