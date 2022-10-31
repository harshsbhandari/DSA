https://practice.geeksforgeeks.org/batch-problems/bfs-traversal-of-graph/0/?track=DSASP-Graph&batchId=154

vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        vector<int>ans;
        int vis[n] = {0};
        queue<int>q;
        
        q.push(0);
        vis[0] = 1;
        ans.push_back(0);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
                
            for(auto i : adj[node]){
                if(!vis[i]){
                    q.push(i);
                    vis[i] = 1;
                    ans.push_back(i);
                }
            }
        }
        
        return ans;
    }
