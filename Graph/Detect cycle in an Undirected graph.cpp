https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

DFS - 
  
bool dfs(int node, int parent, vector<int>adj[], vector<int>&vis){
        vis[node] = 1;
        
        for(auto i : adj[node]){
            if(!vis[i]){
                if(dfs(i, node, adj, vis))
                    return true;
            }
            else if(i != parent)
                return true;
        }
        
        return false;
    }
    
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        vector<int>vis;
        for(int i = 0; i < n; i++)
            vis.push_back(0);
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(dfs(i, -1, adj, vis))
                    return true;
            }
        }
        
        return false;
    }

BFS - 
  
bool bfs(int src, vector<int>adj[], vector<int>&vis){
        vis[src] = 1;
        queue<pair<int,int>>q;
        q.push({src, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto i : adj[node]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push({i, node});
                }
                else if(parent != i)
                    return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        vector<int>vis;
        for(int i = 0; i < n; i++)
            vis.push_back(0);
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(bfs(i, adj, vis))
                    return true;
            }
        }
        
        return false;
    }
