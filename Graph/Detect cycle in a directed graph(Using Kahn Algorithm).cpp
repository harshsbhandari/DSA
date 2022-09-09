https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Topological sort can only be applied on a Directed Acyclic Graph(DAG), and we use it here.

bool isCyclic(int n, vector<int> adj[]) {
        // code here
      vector<int>ans, indegree(n, 0);
	    queue<int>q;
	    
	    for(int it = 0; it < n; it++){
	        for(auto i : adj[it])
	            indegree[i]++;
	    }
	    
	    for(int i = 0; i < indegree.size(); i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        //  node is in the topo sort, so please remove it from the indegree
	        for(auto i : adj[node]){
	            indegree[i]--;
	            if(indegree[i] == 0)
	                q.push(i);
	        }
	    }
	    
	    if(ans.size() == n)
	        return false;
	        
	    return true;
    }
