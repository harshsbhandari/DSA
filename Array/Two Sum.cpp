https://leetcode.com/problems/two-sum/

vector<int> twoSum(vector<int>& arr, int t) {
        vector<int>v;
        map<int,int>m;
        
        for(int i = 0; i < arr.size(); i++){
            int x = t-arr[i];
            if(m.find(x) != m.end()){
                v.push_back(m[x]);
                v.push_back(i);
                break;
               
            }
            m[arr[i]] = i;
        }
        
        return v;
    }
