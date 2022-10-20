https://leetcode.com/problems/k-diff-pairs-in-an-array/

int findPairs(vector<int>& arr, int k) {
        int count = 0;
        map<int,int>m;
        
        for(int i = 0; i < arr.size(); i++)
            m[arr[i]]++;
        
        if(k == 0){
            for(auto i : m){
                if(i.second > 1)
                    count++;
            }
        }
        else{
            for(auto i : m){
                if(m.count(i.first+k) > 0)
                    count++;
            }
        }
        
        return count;
    }
