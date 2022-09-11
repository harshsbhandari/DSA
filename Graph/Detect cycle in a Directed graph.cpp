https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

bool dfs(int node, vector<int> adj[],  vector<int>& vis,  vector<int>& pathvis){
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto i : adj[node]){
            //  if the node is not visited
            
            if(!vis[i]){
                //  if we get a cycle while doing the traversal
                if(dfs(i, adj, vis, pathvis) == true)
                    return true;
            }
            /*
                if the node has been previously visited but it has to be visited 
                on the same path
            */
            else if(vis[i] && pathvis[i])
                return true;
        }
        //  marking the path as unvisited while going back
        
        pathvis[node] = 0;
        return false;
    }
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        vector<int>vis(n, 0), pathvis(n, 0);
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathvis) == true)
                    return true;
            }
        }
        
        return false;
    }
