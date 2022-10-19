https://leetcode.com/problems/search-a-2d-matrix/

bool searchMatrix(vector<vector<int>>& arr, int x) {
        int n = arr.size(), m = arr[0].size();
        int l = 0, h = n*m-1, mid;
        
        while(l <= h){
            mid = (l+h) / 2;
            
            if(arr[mid/m][mid%m] == x)
                return true;
            
            else if(arr[mid/m][mid%m] > x)
                h = mid-1;
            
            else
                l = mid+1;
        }
        
        return false;
    }
