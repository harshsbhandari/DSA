https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix

vector<int> dijkstra(int n, vector<vector<int>> adj[], int src){
        // Code here
        
        vector<int>dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                int nodeWeight = it[1];
                
                if((dis + nodeWeight) < dist[adjNode]){
                    dist[adjNode] = (dis + nodeWeight);
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
