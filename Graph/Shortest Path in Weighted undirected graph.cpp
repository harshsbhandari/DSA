https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        vector<int>ans, parent(n+1), dist(n+1, INT_MAX);
        vector<pair<int,int>>adj[n+1];
        
        for(int i = 1; i <= n; i++)
            parent[i] = i;
        
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
    
        dist[1] = 0;
        pq.push({0, 1});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int nodeWeight = it.second;
                
                if((dis + nodeWeight) < dist[adjNode]){
                    dist[adjNode] = (dis + nodeWeight);
                    pq.push({(dis + nodeWeight), adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        if(dist[n] == INT_MAX){
            ans.push_back(-1);
            return ans;
        }
        
        int node = n;
        
        while(node != parent[node]){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
