https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

DFS -
        
void dfs(vector<vector<int>>& v, int ic, int nc, int sr, int sc, int delr[], int delc[]){
        v[sr][sc] = nc;
        
        for(int i = 0; i < 4 ; i++){
            int newr = delr[i]+sr;
            int newc = delc[i]+sc;
            
            if(newr >= 0 && newr < v.size() && newc >= 0 && newc <= v[0].size() &&
               v[newr][newc] != nc && v[newr][newc] == ic)
                   dfs(v, ic, nc, newr, newc, delr, delc);
            
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& arr, int sr, int sc, int nc) {
        vector<vector<int>>v = arr;
        int ic = v[sr][sc];
        int delr[] = {-1, 0, 1, 0}; 
        int delc[] = {0, 1, 0, -1};
        
        dfs(v, ic, nc, sr, sc, delr, delc);
        
        return v;
    }


BFS - 

void bfs(int sr, int sc, int newColor, vector<vector<int>>&arr){
        int oldColor = arr[sr][sc];
        queue<pair<int,int>>q;
        int delr[] = {0, 0, 1, -1};
        int delc[] = {1, -1, 0, 0};
        int n = arr.size();
        int m = arr[0].size();
        
        q.push({sr, sc});
        arr[sr][sc] = newColor;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int newr = delr[i]+row;
                int newc = delc[i]+col;
                
                if(newr >= 0 && newr < n && newc >= 0 && newc < m && arr[newr][newc] != newColor && arr[newr][newc] == oldColor){
                    arr[newr][newc] = newColor;
                    q.push({newr, newc});
                }
            }
        }
    
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>>arr = image;
        
        bfs(sr, sc, newColor, arr);
        
        return arr;
    }
