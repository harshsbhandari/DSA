https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        // code here
        vector<int>ans, indegree(n, 0);
        vector<int>adjrev[n];
        queue<int>q;
        
        for(int i = 0; i < n; i++){
            // i->it need to converted to it->i
            for(auto it : adj[i]){
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto i : adjrev[node]){
                indegree[i]--;
                
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
