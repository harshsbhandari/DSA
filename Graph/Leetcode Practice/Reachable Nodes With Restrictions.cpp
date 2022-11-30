https://leetcode.com/problems/reachable-nodes-with-restrictions/description/

int count = 0;
    void dfs(vector<int>adj[], set<int>&st, int node, vector<int>&vis, int& count){
      
        // If node is not a restricted than only visit this node
        if(st.find(node) == st.end()){
            vis[node] = 1;
            count++;

            for(auto i : adj[node]){
                if(!vis[i])
                    dfs(adj, st, i, vis, count);
            }
        }

    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int>adj[n];
        int count = 0;
        vector<int>vis(n, 0);

        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        set<int>st;
        
        for(auto i : restricted)
            st.insert(i);
        
        if(!vis[0])
            dfs(adj, st, 0, vis, count);
    
        return count;
    }
