https://practice.geeksforgeeks.org/batch-problems/depth-first-traversal-for-a-graph/0/?track=DSASP-Graph&batchId=154

void dfs(int source, vector<int> adj[], vector<int>&ans, int vis[]){
        ans.push_back(source);
        vis[source] = 1;
        
        for(auto i : adj[source]){
            if(!vis[i])
                dfs(i, adj, ans, vis);
        }
        
    }
    
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        int vis[n] = {0};
        int source = 0;
        vector<int>ans;
        
        dfs(source, adj, ans, vis);
    
        return ans;
    }
