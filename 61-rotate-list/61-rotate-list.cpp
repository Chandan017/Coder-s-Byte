/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        ListNode* temp=head;
        int len=1;
        if(head==NULL || head->next==NULL || k==0)
            return head;
        
        while(temp->next && ++len)
            temp=temp->next;
        
        k=k%len;
        k=len-k;
        temp->next=head;
        
        while(k--)
            temp=temp->next;
        
        head=temp->next;
        temp->next=NULL;
        
        return head;
        
    }
};