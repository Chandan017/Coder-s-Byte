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
    void reorderList(ListNode* head) {
        
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* temp = slow->next;
        slow->next = NULL;
        
        slow = temp;
        ListNode* prevptr = NULL , *currptr = slow  , *nextptr = slow;
        
        while(currptr)
        {
            nextptr = currptr ->next;
            currptr->next = prevptr ;
            prevptr = currptr;
            currptr = nextptr;
        }
        
        fast = prevptr;
        slow = head;
        
        while(fast && slow)
        {
            ListNode* temp1 = NULL , *temp2 = NULL;
            
            temp1 = slow->next;
            temp2 = fast->next;
            
            slow->next = fast ;
            fast->next = temp1;
            
            slow = temp1;
            fast = temp2;
        }
        
        return ;
    }
};