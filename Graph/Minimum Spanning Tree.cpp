https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree

int spanningTree(int n, vector<vector<int>> adj[]){
        // code here
        vector<int>vis(n, 0);
        int sum = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        pq.push({0, 0});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            
            if(vis[node] == 1)
                continue;
                
            // this is where we add a node to mst
            vis[node] = 1;
            sum += wt;
            
            for(auto i : adj[node]){
                int adjNode = i[0];
                int edgeWeight = i[1];
                
                if(!vis[adjNode])
                    pq.push({edgeWeight, adjNode});
            }
        }
        
        return sum;
    }
