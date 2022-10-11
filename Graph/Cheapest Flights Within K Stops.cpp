https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=cheapest-flights-within-k-stops

int CheapestFLight(int n, vector<vector<int>>& flights, int src, int desti, int k)  {
        // Code here
        
        vector<pair<int,int>>adj[n];
        vector<int>dist(n, INT_MAX);
        
        // {stops, {node, dist}}
        queue<pair<int, pair<int,int>>>q;
        
        for(auto it : flights)
            adj[it[0]].push_back({it[1], it[2]});
        
        q.push({0, {src, 0}});
        dist[src] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            q.pop();
            
            if(stops > k)
                continue;
            
            for(auto i : adj[node]){
                int adjNode = i.first;
                int edgeWeight = i.second;
                
                if(edgeWeight+cost < dist[adjNode] && stops <= k){
                    dist[adjNode] = edgeWeight+cost;
                    q.push({stops+1, {adjNode, cost+edgeWeight}});
                }
            }
            
        }
        if(dist[desti] != INT_MAX)
            return dist[desti];
            
        return -1;
    }
