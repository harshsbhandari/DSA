https://leetcode.com/problems/search-in-rotated-sorted-array/

    int search(vector<int>& arr, int x) {
        
        int n = arr.size(), low = 0, high = n-1;
        
        while(low <= high){
            int mid = (low+high)/2;
            
            if(arr[mid] == x)
                return mid;
            
            else if(arr[mid] >= arr[low]){
                if(x >= arr[low] && arr[mid] >= x)
                    high = mid-1;
                else
                    low = mid+1;
            }
            
            else{
                if(arr[high] >= x && x >= arr[mid])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        
        return -1;
    }
