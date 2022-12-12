https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/

// Reverse all the directed edges of the graph and keep storing visited node

void dfs(int node, vector<int>adj[], vector<int>&vis, vector<int>&temp){
        vis[node] = 1;
        temp.push_back(node);

        for(auto i : adj[node]){
            if(!vis[i])
                dfs(i, adj, vis, temp);
            
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        
        for(auto i : edges){
            int u = i[0], v = i[1];
            adj[v].push_back(u);
        }

        vector<vector<int>>ans;

        for(int i = 0; i < n; i++){
            vector<int>temp;
            // always keep 'visited array' set to zero for every node, to get every parent node
            vector<int>vis(n, 0);

            dfs(i, adj, vis, temp);

            if(!temp.empty())
                temp[0] = INT_MAX;

            sort(temp.begin(), temp.end());
            temp.pop_back();
            ans.push_back(temp);
        }

        return ans;
    }
