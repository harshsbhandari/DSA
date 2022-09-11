https://practice.geeksforgeeks.org/problems/alien-dictionary/1

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
    
    string findOrder(string arr[], int n, int k) {
        //code here
        
        vector<int>adj[k];
        
        for(int i = 0; i < n-1; i++){
            string s1 = arr[i];
            string s2 = arr[i+1];
            
            int len = min(s1.length(), s2.length());
            
            for(int j = 0; j < len; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        vector<int>ans = topoSort(k, adj);
        string x="";
        
        for(auto i : ans)
            x = x+char(i+'a');
        
        return x;
    }
