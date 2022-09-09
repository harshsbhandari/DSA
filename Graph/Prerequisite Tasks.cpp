https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1

bool isPossible(int n, vector<pair<int, int> >& prerq) {
	    // Code here
	    vector<int>adj[n];
	    
	    for(auto it : prerq)
	        adj[it.first].push_back(it.second);
	       
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
	        return true;
	        
	    return false;
	    
	}
