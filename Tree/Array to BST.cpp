https://practice.geeksforgeeks.org/problems/array-to-bst4443/1?page=2&company[]=Cisco&sortBy=submissions

void fun(vector<int>& ans, vector<int>& arr, int start, int end){
        if(start > end)
            return ;
        
        int mid = (start+end)/2;
        
        ans.push_back(arr[mid]);
        
        fun(ans, arr, start, mid-1);
        fun(ans, arr, mid+1, end);
        
        return ;
    }
    
    vector<int> sortedArrayToBST(vector<int>& arr) {
        // Code here
        vector<int>ans;
        int start = 0, end = arr.size()-1;
        fun(ans, arr, start, end);
        
        return ans;
    }
