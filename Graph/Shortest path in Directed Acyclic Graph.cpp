https://practice.geeksforgeeks.org/batch-problems/shortest-path-in-undirected-graph/1/?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-directed-acyclic-graph#

void toposort(int& node, vector<pair<int,int>> adj[], stack<int>& st, vector<int>& vis){
	    vis[node] = 1;
	    
	    for(auto i : adj[node]){
	        int v = i.first;
	        if(!vis[v])
	            toposort(v, adj, st, vis);
	    }
	    
	    st.push(node);
	}
	
    vector<int> shortestPath(int n,int m, vector<vector<int>>& arr){
        // code here
        vector<pair<int,int>>adj[n];
        
        for(int i = 0; i < m; i++){
            int u = arr[i][0];
            int v = arr[i][1];
            int wt = arr[i][2];
            
            adj[u].push_back({v, wt});
        }
        
        // doing the topo-sort
        
        vector<int>vis(n, 0);
        stack<int>st;
        
        for(int i = 0; i < n; i++){
            if(!vis[i])
                toposort(i, adj, st,vis);
        }
        
        vector<int>dist(n, 1e9);
        
        // it is the source node
        dist[0] = 0;
        
        while(!st.empty()){
            int u = st.top();
            st.pop();
            
            for(auto i : adj[u]){
                int v = i.first;
                int wt = i.second;
                
                if(dist[u]+wt < dist[v])
                    dist[v] = dist[u]+wt;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(dist[i] == 1e9)
                dist[i] = -1;
        }
        
        return dist;
    }
