https://leetcode.com/problems/spiral-matrix/

vector<int> spiralOrder(vector<vector<int>>& arr) {
        int top, bottom, left, right;
        vector<int>v;
        int n = arr.size(), m = arr[0].size(), d = 1;
        top = 0, bottom = n-1, left = 0, right = m-1;
        
        while(v.size() < n*m){
            
            if(d == 1){
                for(int i = left; i <= right; i++)
                    v.push_back(arr[top][i]);
                top++;
                d = 2;
            }
            else if(d == 2){
                for(int i = top; i <= bottom; i++)
                    v.push_back(arr[i][right]);
                right--;
                d = 3;
            }
            else if(d == 3){
                for(int i = right; i >= left; i--)
                    v.push_back(arr[bottom][i]);
                bottom--;
                d = 4;
            }
            
            else if(d == 4){
                for(int i = bottom; i >= top; i--)
                    v.push_back(arr[i][left]);
                left++;
                d = 1;
            }
        }
        
        return v;
    }
