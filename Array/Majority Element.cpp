https://leetcode.com/problems/majority-element/

int majorityElement(vector<int>& v) {
        int count = 1, no = v[0];
  
        for(int i = 1; i < v.size(); i++){
            if(v[i] == no)
                count++;
            else 
                count--;
            
            if(count <= 0){
                ++i;
                no = v[i];
                count = 1;
            }
        }
        
        return no;
    }
