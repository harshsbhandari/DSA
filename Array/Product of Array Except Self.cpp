https://leetcode.com/problems/product-of-array-except-self/

vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int>v;
        
        int countZero = count(arr.begin(), arr.end(), 0);
        
        if(countZero > 1){
            vector<int>x(n ,0);
            return x;
        }
        else if(countZero == 0){
            int q = 1;
            for(int i = 0; i < n; i++)
                q *= arr[i];
            
            for(int i = 0; i < n; i++)
                v.push_back(q/arr[i]);
        }
        else if(countZero == 1){
            int q = 1;
            for(int i = 0; i < n; i++){
                if(arr[i] != 0)
                    q *= arr[i];
            }
            
            for(int i = 0; i < n; i++){
                if(arr[i] == 0)
                    v.push_back(q);
                else
                    v.push_back(0);
            }
        }
        
        return v; 
    }
