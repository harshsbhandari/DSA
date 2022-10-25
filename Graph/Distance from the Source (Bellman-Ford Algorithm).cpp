https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-from-the-source-bellman-ford-algorithm

vector<int> bellman_ford(int n, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(n, 1e8);
        dist[src] = 0;
        
        for(int i = 0; i < n-1; i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if((dist[u]+wt < dist[v]) && dist[u] != 1e8)
                    dist[v] = wt+dist[u];
            }
        }
        
        // N'th relaxation is done to check whether negative cycle exists
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if((dist[u]+wt < dist[v]) && dist[u] != 1e8)
                return {-1};
        }
        
        return dist;
    }
