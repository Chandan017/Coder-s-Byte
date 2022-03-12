/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* temp=head, *front=head;
        
        while(temp)
        {
            Node* copy=new Node(temp->val);
            
            copy->next=temp->next;
            temp->next=copy;
            
            temp=temp->next->next;
        }
        
        
        
        temp=head;
        
        while(temp)
        {
            if(temp->random)
                temp->next->random=temp->random->next;
            
            temp=temp->next->next;
        }
        
        
        
        temp=head;
        Node* newHead=new Node(0);
        Node* copy=newHead;
        while(temp)
        {
            front=temp->next->next;
            
            copy->next=temp->next;
            temp->next=front;
            
            temp=front;
            copy=copy->next;
            
        }
        
        
        return newHead->next;
    }
};