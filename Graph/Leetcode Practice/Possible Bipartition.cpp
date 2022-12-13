https://leetcode.com/problems/possible-bipartition/description/

bool dfs(int node, vector<int>adj[], vector<int>& color, int colors){
	    color[node] = colors;
	    
	    for(auto i : adj[node]){
	        if(color[i] == -1){
	            if(dfs(i, adj, color, !colors) == false)
	                return false;
	        }
	        else{
	            if(color[i] == color[node])
	                return false;
	        }
	    }
	    
	    return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];

        for(auto i : dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int>color(n+1, -1);
	    
	    for(int i = 0; i <= n; i++){
	        if(color[i] == -1){
	            if(dfs(i, adj, color, 0) == false)
	                return false;
	        }
	    }
	    return true;
    }
