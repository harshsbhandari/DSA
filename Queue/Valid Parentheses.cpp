https://leetcode.com/problems/valid-parentheses/

bool isValid(string x) {    
        stack<char>s;
        int n = x.length();
        
        for(int i = 0; i < n; i++){
            if(x[i] == '(' || x[i] == '{' || x[i] == '['){
                s.push(x[i]);
                continue;
            }
            
            if(s.empty())
                return false;
            
            char temp = s.top();
            
            switch(x[i]){
                    
                case ')':
                    s.pop();
                    if(temp != '(')
                        return false;
                    break;
                    
                case '}':
                    s.pop();
                    if(temp != '{')
                        return false;
                    break;
                    
                case ']':
                    s.pop();
                    if(temp != '[')
                        return false;
                    break;
            }
            
        }
        
        return s.empty();
        
    }
