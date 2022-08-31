https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1

void dfs(vector<vector<int>>& vis, vector<vector<char>>arr, int row, int col, int delr[], int delc[], int n, int m){
        vis[row][col] = 1;
        
        for(int i = 0; i < 4; i++){
            int newr = delr[i]+row; 
            int newc = delc[i]+col;
            
            if(newr < n && newr >= 0 && newc < m && newc >= 0 && vis[newr][newc] == 0 && arr[newr][newc] == 'O')
                dfs(vis, arr, newr, newc, delr, delc, n, m);
        }
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        // code here
        
        vector<vector<char>>arr = mat;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        int delr[] = {0, 1, -1, 0};
        int delc[] = {1, 0, 0, -1};
        
        for(int i = 0; i < n; i++){
            if(arr[i][0] == 'O' && vis[i][0] == 0)
                dfs(vis, arr, i, 0, delr, delc, n, m);
                
            if(arr[i][m-1] == 'O' && vis[i][m-1] == 0)
                dfs(vis, arr, i, m-1, delr, delc, n, m);
        }
        
        for(int j = 0; j < m; j++){
            if(arr[0][j] == 'O' && vis[0][j] == 0)
                dfs(vis, arr, 0, j, delr, delc, n, m);
            
            if(arr[n-1][j] == 'O' && vis[n-1][j] == 0)
                dfs(vis, arr, n-1, j, delr, delc, n, m);
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] != 1)
                    arr[i][j] = 'X';
            }
        }
        
        return arr;
    }
