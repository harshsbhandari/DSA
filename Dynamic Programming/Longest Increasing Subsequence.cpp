https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

int longestSubsequence(int n, int arr[]){
        // your code here
        vector<int>dp(n, 1);
           
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(dp[j]+1 > dp[i] && arr[j] < arr[i])
                    dp[i] = dp[j]+1;
            }
        }
           
        return *max_element(dp.begin(), dp.end());
    }
