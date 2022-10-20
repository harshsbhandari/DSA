https://leetcode.com/problems/subarray-sums-divisible-by-k/

int subarraysDivByK(vector<int>& arr, int k) {
        int n = arr.size(), count = 0;
        map<int,int>m;
        m[0] = 1;
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            
            int temp = sum % k;
          
            if(temp < 0)
                temp += k;
        
            count += m[temp];
            m[temp]++;
               
        }
        
        return count;
    }
