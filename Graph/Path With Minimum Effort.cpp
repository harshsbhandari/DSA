https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort

int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        
        int n = heights.size(), m = heights[0].size();
        priority_queue<pair<int,int>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>pq;
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        
        int delr[] = {0, 1, 0, -1};
        int delc[] = {-1, 0, 1, 0};
        
        while(!pq.empty()){
            auto it = pq.top();
            int diff = it.first;
            int x = it.second.first;
            int y = it.second.second;
            pq.pop();
            
            if(x == n-1 && y == m-1)
                return diff;
            
            for(int i = 0; i < 4; i++){
                int newr = x+delr[i];
                int newc = y+delc[i];
                
                if(newr >= 0 && newr < n && newc >= 0 && newc < m){
                    int newEffort = max(diff, abs(heights[x][y] - heights[newr][newc]));
                
                    if(newEffort < dist[newr][newc]){
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        
        return 0;
    }
