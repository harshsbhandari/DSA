https://practice.geeksforgeeks.org/batch-problems/depth-first-traversal-for-a-graph/0/?track=DSASP-Graph&batchId=154

void dfs(int source, vector<int> adj[], vector<int>&v, int vis[]){
        v.push_back(source);
        vis[source] = 1;
        
        for(auto i : adj[source]){
            if(!vis[i])
                dfs(i, adj, v, vis);
        }
        
    }
    
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        int vis[n] = {0};
        int source = 0;
        vector<int>v;
        
        dfs(source, adj, v, vis);
    
        return v;
    }
