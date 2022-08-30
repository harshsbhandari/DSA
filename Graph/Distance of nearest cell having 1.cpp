https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

vector<vector<int>>nearest(vector<vector<int>>arr){
	    // Code here
	    int n = arr.size(), m = arr[0].size();
	    vector<vector<int>>dist(n, vector<int>(m, 0));
	    vector<vector<int>>vis(n, vector<int>(m, 0));
	    queue<pair<pair<int,int>,int>>q;
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            if(arr[i][j] == 1){
	                q.push({{i,j}, 0});
	                vis[i][j] = 1;
	            }
	            else
	                vis[i][j] = 0;
	        }
	    }
	    
	    int delr[] = {-1, 0, 1, 0};
	    int delc[] = {0, 1, 0, -1};
	        
	    while(!q.empty()){
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int step = q.front().second;
	        q.pop();
	        
	        dist[row][col] = step;
	        
	        for(int i = 0; i < 4; i++){
	            int newr = delr[i]+row;
	            int newc = delc[i]+col;
	            
	            if(newr >= 0 && newr < n && newc >= 0 && newc < m && vis[newr][newc] == 0){
	                vis[newr][newc] = 1;
	                q.push({{newr,newc}, step+1});
	            }
	            
	        }
	        
	    }
	    
	    return dist;
	}
