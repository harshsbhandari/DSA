https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands

DFS - 
  
void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int,int>>& v, int row0, int col0){
        vis[row][col] = 1;
        v.push_back({row-row0, col-col0});
        
        int n = grid.size();
        int m = grid[0].size();
        
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, -1, 0, 1};
        
        for(int i = 0; i < 4; i++){
            int newr = row+delr[i];
            int newc = col+delc[i];
            
            if(newr >= 0 && newr < n && newc >= 0 && newc < m && vis[newr][newc] == 0 && grid[newr][newc] == 1)
                dfs(newr, newc, grid, vis, v, row0, col0);
        }
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m , 0));
        set<vector<pair<int,int>>>s;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>>v;
                    dfs(i, j, grid, vis, v, i, j);
                    s.insert(v);
                }
            }
        }
        
        return s.size();
    }

BFS - 
  
  void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int,int>>& v, int row0, int col0){
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, -1, 0, 1};
        
        q.push({row, col});
        vis[row][col] = 1;
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            v.push_back({x-row0, y-col0});
            
            for(int i = 0; i < 4; i++){
                int newr = x+delr[i];
                int newc = y+delc[i];
                
                if(newr >= 0 && newr < n && newc >= 0 && newc < m && vis[newr][newc] == 0 && grid[newr][newc] == 1){
                    q.push({newr, newc});
                    vis[newr][newc] = 1;
                }
            }
        }
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m , 0));
        set<vector<pair<int,int>>>s;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>>v;
                    bfs(i, j, grid, vis, v, i, j);
                    s.insert(v);
                }
            }
        }
        
        return s.size();
    }
