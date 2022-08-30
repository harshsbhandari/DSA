https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

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
