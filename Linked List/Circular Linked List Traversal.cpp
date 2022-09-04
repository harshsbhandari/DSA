https://practice.geeksforgeeks.org/problems/circular-linked-list-traversal/1?page=2&company[]=Cisco&sortBy=submissions

void printList(struct Node *head){
    // code here
    Node* temp = head;
  
    if(head != NULL) {
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while (temp != head);
    }
  
}
