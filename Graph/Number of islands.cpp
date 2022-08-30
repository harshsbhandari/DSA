https://practice.geeksforgeeks.org/batch-problems/find-the-number-of-islands/0/?track=DSASP-Graph&batchId=154#

DFS -
void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& arr, int n, int m){
        vis[row][col] = 1;
       
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                
                int nr = i+row;
                int nc = j+col;
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && 
                  (vis[nr][nc] == 0) && (arr[nr][nc] == '1'))
                    dfs(nr, nc, vis, arr, n, m);
                
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((vis[i][j] == 0) && (arr[i][j] == '1')){
                    dfs(i, j, vis, arr, n, m);
                    count++;
                }
            }
        }
        
        return count;
    }
    
BFS -

void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& arr, int n, int m){
        vis[row][col] = 1;
        
        queue<pair<int,int>>q;
        q.push({row,col});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop(); 
            
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int nr = i+row;
                    int nc = j+col;
                    
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && 
                      (vis[nr][nc] == 0) && (arr[nr][nc] == '1')){
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((vis[i][j] == 0) && (arr[i][j] == '1')){
                    bfs(i, j, vis, arr, n, m);
                    count++;
                }
            }
        }
        
        return count;
    }
    
    
