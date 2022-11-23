https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo

//Function to find number of strongly connected components in the graph.
	void dfs(int src, vector<int>adj[], stack<int>&st, vector<int>&vis){
	    vis[src] = 1;
	    
	    for(auto i : adj[src]){
	        if(!vis[i])
	            dfs(i, adj, st, vis);
	    }
	    
	    st.push(src);
	}
	
	void simpleDfs(int src, vector<int>adj[], vector<int>&vis){
	    vis[src] = 1;
	    
	    for(auto i : adj[src]){
	        if(!vis[i])
	            simpleDfs(i, adj, vis);
	    }
	}
	
    int kosaraju(int n, vector<int> adj[]){
        vector<int>vis(n, 0);
        stack<int>st;
        
        // step 1 - Sorting all the edges according to the finishing time.
        for(int i = 0; i < n; i++){
            if(!vis[i])
                dfs(i, adj, st, vis);
        }
        
        // step 2 - Reversing the graph
        vector<int>revadj[n];
        
        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                // There is an edge from 'i' to 'it'
                // We reverse it, and make it from 'it' to 'i'
                revadj[it].push_back(i);
            }
        }
        
        int count = 0;
        
        // Reusing visited array
        for(int i = 0; i < n; i++)
            vis[i] = 0;
        
        // step 3 - Do simple DFS with reversed graph
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                simpleDfs(node, revadj, vis);
                count++;
            }
            
        }
        
        return count;
    }
