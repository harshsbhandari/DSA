https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>arr(n, vector<int>(n, INT_MAX));
        
        for(auto i : edges){
            int x = i[0];
            int y = i[1];
            int wt = i[2];
            
            arr[x][y] = wt;
            arr[y][x] = wt;
        }
        
        for(int i = 0; i < n; i++)
            arr[i][i] = 0;
        
        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(arr[i][via] == INT_MAX || arr[via][j] == INT_MAX)
                        continue;
                    arr[i][j] = min(arr[i][j], arr[i][via]+arr[via][j]);
                }
            }
        }
        
        int cityNo = -1, countCity = n;
        
        for(int i = 0; i < n; i++){
            int count = 0;
            
            for(int j = 0; j < n; j++){
                if(arr[i][j] <= distanceThreshold)
                    count++;
            }
            
            if(count <= countCity){
                countCity = count;
                cityNo = i;
            }
        }
        
        return cityNo;
    }
