https://leetcode.com/problems/decode-string/

string decodeString(string s) {
        string x;
        
        stack<char>st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ']'){
                st.push(s[i]);
                continue;
            }
            
            string temp;
          
            while(st.top() != '['){
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            st.pop();
            
            int num = 0;
            string no;
          
            while(!st.empty() && (st.top()-'0' < 10)){
                no += st.top();
                st.pop();
            }
            reverse(no.begin(), no.end());
            num = stoi(no);
            
            string rep;
          
            for(int j = 0; j < num; j++)
                rep += temp;
            
            for(int j = 0; j < rep.length(); j++)
                st.push(rep[j]);
        }
        
        while(!st.empty()){
            x += st.top();
            st.pop();
        }
        
        reverse(x.begin(), x.end());
        
        return x;
    }
