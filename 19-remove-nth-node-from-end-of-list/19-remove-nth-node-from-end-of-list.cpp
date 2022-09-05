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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
                
        ListNode* temp1 = head , *temp2 = head;
        
        while(n--)
            temp1 = temp1->next;
        
        if(!temp1)
            return head->next;
        
        while(temp1->next)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        temp2->next = temp2->next->next;
        
        return head;
            
        
    }
};