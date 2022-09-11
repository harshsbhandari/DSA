https://practice.geeksforgeeks.org/batch-problems/shortest-path-in-undirected-graph-having-unit-distance/1/?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-unit-distance

vector<int> shortestPath(vector<vector<int>>& arr, int n,int m, int src){
        // code here
        vector<int>adj[n], dist(n, INT_MAX);
        
        for(auto i : arr){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        queue<int>q;
        
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto i : adj[node]){
                if(dist[node]+1 < dist[i]){
                    dist[i] = dist[node]+1;
                    q.push(i);
                }
            }
            
        }
        
        for(int i = 0; i < n; i++){
            if(dist[i] == INT_MAX)
                dist[i] = -1;
        }
        
        return dist;
    }
