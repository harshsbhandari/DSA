https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=/number-of-ways-to-arrive-at-destination

int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        
        // {node, weight}
        vector<pair<int,int>>adj[n];
        // {distance, node} 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(n, INT_MAX), ways(n, 0);
        int mod = (int)(1e9+7);
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        while(!pq.empty()){
            auto it = pq.top();
            int dis = it.first;
            int node = it.second;
            pq.pop();
            
            for(auto i : adj[node]){
                int adjNode = i.first;
                int edgeWeight = i.second;
                int totalDist = dis+edgeWeight;
                
                if(totalDist < dist[adjNode]){
                    dist[adjNode] = totalDist;
                    ways[adjNode] = ways[node];
                    pq.push({totalDist, adjNode});
                }
                else if(totalDist == dist[adjNode])
                    ways[adjNode] = (ways[adjNode] + ways[adjNode]) % mod;
            }
        }
        
        return (ways[n-1] % mod);
    }
