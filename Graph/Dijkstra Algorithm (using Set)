https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix

vector<int> dijkstra(int n, vector<vector<int>> adj[], int src){
        // Code here
        
        vector<int>dist(n, INT_MAX);
        set<pair<int,int>>st;
        
        dist[src] = 0;
        st.insert({0, src});
        
        while(!st.empty()){
            auto i = *(st.begin());
            int dis = i.first;
            int node = i.second;
            st.erase(i);
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                int nodeWeight = it[1];
                
                if((dis + nodeWeight) < dist[adjNode]){
                    
                    // erase if dist[adjNode] has been previously visited
                    if(dist[adjNode] != INT_MAX)
                        st.erase({dist[adjNode], adjNode});
                        
                    dist[adjNode] = (dis + nodeWeight);
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
