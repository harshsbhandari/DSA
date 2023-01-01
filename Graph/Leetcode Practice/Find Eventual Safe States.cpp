https://leetcode.com/problems/find-eventual-safe-states/description/

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>ans, indegree(n, 0);
        vector<int>adjrev[n];
        queue<int>q;
        
        for(int i = 0; i < n; i++){
            for(auto it : graph[i]){
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
