https://leetcode.com/problems/coin-change/

int coinChange(vector<int>& arr, int sum) {
        int n = arr.size();
        int dp[n+1][sum+1];
        
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < sum+1; j++){
                if(i == 0)
                    dp[i][j] = INT_MAX-1;
                else if(j == 0)
                    dp[i][j] = 0;
            }
        }
        
        // for first row where (i == 1)
        for(int j = 1; j < sum+1; j++){
            if(j%arr[0] == 0)
                dp[1][j] = j/arr[0];
            else
                dp[1][j] = INT_MAX-1;
        }
        
        // (i == 1) has been filled, so now we start to fill from (i == 2)
        for(int i = 2; i < n+1; i++){
            for(int j = 1; j < sum+1; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = min(1+dp[i][j-arr[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        if(dp[n][sum] != INT_MAX-1)
            return dp[n][sum];
        
        return -1;
    }
