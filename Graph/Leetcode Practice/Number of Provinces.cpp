https://leetcode.com/problems/number-of-provinces/description/

/*
  Count number of connected components
*/

void dfs(int node, vector<int>&vis, vector<int>adj[]){
        vis[node] = 1;
        
        for(auto i : adj[node]){
            if(!vis[i])
                dfs(i, vis, adj);
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int>vis(n+1, 0);
        vector<int>adj[n+1];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // (i != j) avoid self loops
                if(arr[i][j] == 1 && (i != j)){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                dfs(i, vis, adj);
            }
        }
        
        return count;
    }
