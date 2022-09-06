https://leetcode.com/problems/linked-list-cycle-ii/

ListNode *detectCycle(ListNode *head) {
        ListNode *f = head;
        ListNode *s = head;
        
        while(f && f->next){
            f = f->next->next;
            s = s->next;
          
            if(f == s)
                break;
        }
        
        if(!(f && f->next))
            return NULL;
        
        f = head;
        
        while(f != s){
            f = f->next;
            s = s->next;
        }
        
        return s; // return f; 
    }
