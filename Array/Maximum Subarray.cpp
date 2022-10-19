https://leetcode.com/problems/maximum-subarray/

int maxSubArray(vector<int>& arr) {
        int temp = arr[0], sum = arr[0], n = arr.size();
        
        for(int i = 1; i < n; i++){
            temp = max(arr[i], temp+arr[i]);
            sum = max(sum, temp);
        }
        
        return sum;
    }
