https://leetcode.com/problems/number-of-provinces/submissions/

    void dfs(int source, vector<int> v[], int vis[]){
        vis[source] = 1;
        
        for(auto i : v[source]){
            if(!vis[i])
                dfs(i, v, vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& arr) {
        int count = 0, n = arr.size();
        vector<int>v[n+1];
        int vis[n+1];
        
        for(int i = 0; i < n+1; i++)
            vis[i] = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 1 && (i != j)){
                     // && (i != j) - for rejecting self loops
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                dfs(i, v, vis);
            }
        }
        
        return count;
    }
