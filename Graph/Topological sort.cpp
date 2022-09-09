https://practice.geeksforgeeks.org/problems/topological-sort/1

void dfs(int& node, vector<int> adj[], stack<int>& st, vector<int>& vis){
	    vis[node] = 1;
	    
	    for(auto i : adj[node]){
	        if(!vis[i])
	            dfs(i, adj, st, vis);
	    }
	    
	    st.push(node);
	}
	
	vector<int> topoSort(int n, vector<int> adj[]){
	    // code here
	    vector<int>ans, vis(n, 0);
	    stack<int>st;
	    
	    for(int i = 0; i < n; i++){
	        if(!vis[i]){
	            dfs(i, adj, st, vis);
	        }
	    }
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
