https://leetcode.com/problems/path-with-maximum-probability/description/

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>adj[n];

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            double wt = succProb[i];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }   

        vector<double>dist(n, INT_MIN);
        // We need maximum value so, INT_MIN filled initially
        priority_queue<pair<double, int>>pq;
        // max-heap required here, always keep the 'distance' or 'weight' in the first place than the 'node'.
        
        pq.push({(double)1, start});
        dist[start] = (double)1;
        // Inserted 1 in above (both) because we calculate the product here
  
        while(!pq.empty()){
            double weight = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto i : adj[node]){
                int adjNode = i.first;
                double adjWeight = i.second;
                 
                // opposite the logic of dijkstra(max required here)
                if(weight*adjWeight > dist[adjNode]){
                    dist[adjNode] = weight*adjWeight;
                    pq.push({weight*adjWeight, adjNode});
                }
            }
        }
        if(dist[end] < 0)
            return 0;

        return dist[end];
    }
