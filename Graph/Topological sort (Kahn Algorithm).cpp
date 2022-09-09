https://practice.geeksforgeeks.org/problems/topological-sort/1

Here, we just solved the Topological Sort problem using BFS 

vector<int> topoSort(int n, vector<int> adj[]){
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
	    
	    return ans;
	}
