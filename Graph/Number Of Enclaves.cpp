https://practice.geeksforgeeks.org/problems/number-of-enclaves/1

BFS -
  
int numberOfEnclaves(vector<vector<int>> &arr) {
        // Code here
        
        int n = arr.size(), m = arr[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int,int>>q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(arr[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        
        int delr[] = {0, 1, -1, 0};
        int delc[] = {1, 0, 0, -1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int newr = delr[i]+row;
                int newc = delc[i]+col;
                
                if(newr >= 0 && newr < n && newc >= 0 && newc < m && vis[newr][newc] == 0 && arr[newr][newc] == 1){
                    q.push({newr, newc});
                    vis[newr][newc] = 1;
                }
            }
            
        }
        
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 0 && arr[i][j] == 1)
                    count++;                
            }
        }
        
        return count;
    }

DFS - 130/132 cases passed (In dfs() arr passed by reference, then all test cases passed)
  
  void dfs(vector<vector<int>> &vis, vector<vector<int>>& arr, int delr[], int delc[], int row, int col, int n, int m){
        vis[row][col] = 1;
        
        for(int i = 0; i < 4; i++){
            int newr = delr[i]+row;
            int newc = delc[i]+col;
            
            if(newr >= 0 && newr < n && newc >= 0 && newc < m && !vis[newr][newc] && arr[newr][newc] == 1)
                dfs(vis, arr, delr, delc, newr, newc, n, m);
        }
        
    }
  
    int numberOfEnclaves(vector<vector<int>> &arr) {
        // Code here
        int n = arr.size(), m = arr[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        int delr[] = {0, 1, 0, -1};
        int delc[] = {1, 0, -1, 0};
        
        for(int i = 0; i < n; i++){
            if(!vis[i][0] && arr[i][0] == 1)
                dfs(vis, arr, delr, delc, i, 0, n, m);
            
            if(!vis[i][m-1] && arr[i][m-1] == 1)
                dfs(vis, arr, delr, delc, i, m-1, n, m);
        }
        
        for(int j = 0; j < m; j++){
            if(!vis[0][j] && arr[0][j] == 1)
                dfs(vis, arr, delr, delc, 0, j, n, m);
            
            if(!vis[n-1][j] && arr[n-1][j] == 1)
                dfs(vis, arr, delr, delc, n-1, j, n, m);
        }
        
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 1 && !vis[i][j])
                    count++;
            }
        }
        
        return count;
    }
