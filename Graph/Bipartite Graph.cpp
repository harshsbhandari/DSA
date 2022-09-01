https://practice.geeksforgeeks.org/problems/bipartite-graph/1

BFS - 
	
bool bfs(int node, vector<int>adj[], vector<int>& color){
	    queue<int>q;
	    q.push(node);
	    color[node] = 0;
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        for(auto i :  adj[node]){
	            if(color[i] == -1){
	                color[i] = !color[node];
	                q.push(i);
	            }
	            else{
	                if(color[i] == color[node])
	                    return false;
	            }
	        }
	    }
	    
	    return true;
    }
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    
	    vector<int>color(n, -1);
	    
	    for(int i = 0; i < n; i++){
	        if(color[i] == -1){
	            if(bfs(i, adj, color) == false)
	            return false;
	        }
	    }
	    return true;
	}

DFS - 

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
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    
	    vector<int>color(n, -1);
	    
	    for(int i = 0; i < n; i++){
	        if(color[i] == -1){
	            if(dfs(i, adj, color, 0) == false)
	                return false;
	        }
	    }
	    return true;
	}
