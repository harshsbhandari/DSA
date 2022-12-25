https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

bool dfs(int node, vector<int> adj[],  vector<int>& vis,  vector<int>& pathvis, vector<int>& check){
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        
        for(auto i : adj[node]){
            //  if the node is not visited
            
            if(!vis[i]){
                //  if we get a cycle while doing the traversal
                if(dfs(i, adj, vis, pathvis, check) == true)
                    return true;
            }
            /*
                if the node has been previously visited but it has to be visited 
                on the same path
            */
            else if(vis[i] && pathvis[i])
                return true;
        }
        
        // marking the node as safe as it was not found in the cycle path
        check[node] = 1;
        //  marking the path as unvisited while going back
        pathvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        // code here
        vector<int>vis(n, 0), pathvis(n, 0), check(n, 0), safe_nodes;
        
        for(int i = 0; i < n; i++){
            if(!vis[i])
                dfs(i, adj, vis, pathvis, check);
        }
        
        for(int i = 0; i < n; i++){
            if(check[i] == 1)
                safe_nodes.push_back(i);
        }
        
        return safe_nodes;
    }
