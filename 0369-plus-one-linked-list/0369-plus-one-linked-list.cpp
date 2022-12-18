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
    ListNode* getReverse(ListNode* node)
    {
        if(!node || !node->next)
            return node;
        ListNode* prevptr = NULL , *currptr = node , *nextptr = NULL;
        
        while(currptr)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        
        return prevptr;
    }
    ListNode* plusOne(ListNode* head) {
        
        ListNode* rev = getReverse(head);
        
        ListNode* temp = rev;
        int carry = 1;
        
        while(temp || carry)
        {
            int curr = temp->val + carry;
            temp->val = curr%10;
            carry = curr/10;
            
            if(temp->next == NULL && carry)
                temp->next = new ListNode(0);
            temp = temp->next;
        }
        
        rev = getReverse(rev);
        return rev;
        
    }
};