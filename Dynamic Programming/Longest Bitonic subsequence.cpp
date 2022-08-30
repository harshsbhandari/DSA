https://www.youtube.com/watch?v=y4vN0WNdrlg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=47

int LongestBitonicSequence(vector<int>arr){
	    // code here
	    int n = arr.size();
	    vector<int>dp1(n, 1), dp2(n, 1);
	    
	    // Longest Increasing Subsequence from left to right
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < i; j++){
	            if((arr[j] < arr[i]) && (dp1[i] < dp1[j]+1))
	                dp1[i] = dp1[j]+1;
	        }
	    }
	    
	    // Longest Increasing Subsequence from right to left
	    for(int i = n-1; i >= 0; i--){
	        for(int j = n-1; j > i; j--){
	            if((arr[j] < arr[i]) && (dp2[i] < dp2[j]+1))
	                dp2[i] = dp2[j]+1;
	        }
	    }
	    
	    int ans = 0;
	    
	    for(int i = 0; i < n; i++)
	        ans = max(ans, dp1[i]+dp2[i]-1);
	        
	    return ans;
	}
