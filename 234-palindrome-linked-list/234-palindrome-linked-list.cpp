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
    
    ListNode* getReverse(ListNode* head)
    {
        if(!head || !head->next)
            return head;
        
        ListNode* prevptr = NULL , *currptr = head , *nextptr = head;
        
        while(currptr)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        
        return prevptr;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow = head , *fast = head;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* secondPart = getReverse(slow);
        
        ListNode* firstPart = head;
        
        while(firstPart && secondPart)
        {
            if(firstPart->val != secondPart->val)
                return false;
            
            firstPart = firstPart->next;
            secondPart = secondPart->next;
        }
        
        return true;
        
        
    }
};