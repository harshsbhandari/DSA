https://leetcode.com/problems/network-delay-time/description/

// Simple Dijkstra Algorithm

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        // {node, weight}

        for(auto i : times){
            int u = i[0], v = i[1], wt = i[2];

            adj[u].push_back({v, wt});
        }

        vector<int>dist(n+1, INT_MAX);
        set<pair<int,int>>st;

        st.insert({0, k});
        // {distance, node}
        dist[k] = 0;

        while(!st.empty()){
            auto it = *(st.begin());
            int distance = it.first;
            int node = it.second;

            st.erase(it);

            for(auto i : adj[node]){
                int adjNode = i.first;
                int nodeWeight = i.second;

                if(nodeWeight+distance < dist[adjNode]){
                    if(dist[adjNode] != INT_MAX)
                        st.erase({dist[adjNode], adjNode});

                    dist[adjNode] = nodeWeight+distance;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        int ans = INT_MIN;

        for(int i = 1; i < n+1; i++)
            ans = max(ans, dist[i]);
        
        if(ans == INT_MAX)
            return -1;

        return ans;
    }   
