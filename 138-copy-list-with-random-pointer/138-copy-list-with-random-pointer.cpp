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
        
        
        Node* temp=head;
        
        while(temp)
        {
            Node* copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            
            temp=copy->next;
        }
        
        
        temp=head;
        
        while(temp)
        {
            Node* originalRandom=temp->random;
            
            temp=temp->next;
            
            if(originalRandom)
                temp->random=originalRandom->next;
            else
                temp->random=NULL;
            temp=temp->next;
        }
        
        Node* newHead=new Node(0);
        Node* front=newHead;
        temp=head;
        
        while(temp)
        {
            front->next=temp->next;
            temp->next=temp->next->next;
            
            temp=temp->next;
            front=front->next;
        }
        
        return newHead->next;
    }
};