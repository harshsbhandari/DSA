https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

/*
  Floyd Warshall Algorithm
*/

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>arr(n, vector<int>(n, 1e9));

        for(auto i : edges){
            int u = i[0], v = i[1], weight = i[2];

            arr[u][v] = weight;
            arr[v][u] = weight;
        }

        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++)
                    arr[i][j] = min(arr[i][j], arr[i][via]+arr[via][j]);   
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 1e9)
                    arr[i][j] = -1;
            }
        }

        int count = INT_MAX, ans = INT_MIN;

        for(int i = 0; i < n; i++){
            int temp = 0;
            
            // (i != j) for avoiding self loop
            for(int j = 0; j < n; j++){
                if(arr[i][j] != -1 && arr[i][j] <= distanceThreshold && (i != j))
                    temp++;
            }

            if(temp <= count){
                count = temp;
        
                if(i >= ans)
                    ans = i;
                  
            }
        }

        return ans;
    }
