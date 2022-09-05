https://leetcode.com/problems/reverse-linked-list/

ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* later;
        
        while(curr){
            later = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = later;
        }
        
        head = prev;
        return head;
    }
