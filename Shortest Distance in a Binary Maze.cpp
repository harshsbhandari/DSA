https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze

int shortestPath(vector<vector<int>> &grid, pair<int,int>src, pair<int,int>desti) {
        // code here
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, pair<int,int>>>q;
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        
        if(src.first == desti.first && src.second == desti.second)
            return 0;
            
        dist[src.first][src.second] = 0;
        q.push({0, {src.first, src.second}});
        
        int delr[] = {0, 1, 0, -1};
        int delc[] = {-1, 0, 1, 0};
        
        while(!q.empty()){
            auto it = q.front();
            int dis = it.first;
            int x = it.second.first;
            int y = it.second.second;
            q.pop();
            
            for(int i = 0 ; i < 4; i++){
                int newr = delr[i] + x;
                int newc = delc[i] + y;
                
                if(newr >= 0 && newr < n && newc >= 0 && newc < m && (grid[newr][newc] == 1) && (dist[newr][newc] > dis+1)){
                    dist[newr][newc] = dis+1;
                    q.push({dis+1, {newr, newc}});
                    
                    if(newr == desti.first && newc == desti.second)
                        return dist[newr][newc];
                }
            }
        }
        
        return -1;
    }
