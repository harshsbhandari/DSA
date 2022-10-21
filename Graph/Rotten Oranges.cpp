https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

int orangesRotting(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size(), m = arr[0].size();
        
        // {{row, col}, time}
        queue<pair<pair<int,int>,int>>q;        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        // the oranges which are rotten initially are put in the queue, for further computation
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        
        int delr[] = {0 , -1, 1, 0};
        int delc[] = {1 , 0, 0, -1};
        int ans = 0;
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            
            ans = max(ans, t);
            q.pop();
            
            // searching in all four direction of the rotten orange that, if there is any unrotten orange that is unvisited
            for(int i = 0; i < 4; i++){
                int newr = delr[i]+row;
                int newc = delc[i]+col;
                
                if(newr >= 0 && newr < n && newc >= 0 && newc < m && 
                   !vis[newr][newc] && arr[newr][newc] == 1){
                       q.push({{newr,newc}, t+1});
                       vis[newr][newc] = 2;
                   }
            }
        }
        
        // checking whether all the fresh oranges have rotten or not
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 1 && vis[i][j] != 2)
                    return -1;
            }
        }
        
        return ans;
    }
