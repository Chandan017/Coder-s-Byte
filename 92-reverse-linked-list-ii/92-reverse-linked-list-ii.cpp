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
    
    ListNode* reverse(ListNode* head)
    {
        if(!head || !head->next)
            return head;
        
        ListNode* currptr = head , *prevptr = NULL , *nextptr ;
        
        while(currptr)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        
        return prevptr;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head || !head->next || left==right)
            return head;
        
        ListNode* prev = NULL , *start , *end , *temp = head;
        int cnt = 1;
        
        while(temp)
        {
            if(cnt == left-1)
                prev = temp;
            else if(cnt == left)
                start = temp;
            else if(cnt == right)
            {
                end = temp->next;
                temp->next = NULL;
            }
            cnt++;
            temp = temp->next;
        }
        
        ListNode* newStart = reverse(start);
        
        start->next = end;
        
        if(prev == NULL)
            head = newStart;
        else
            prev->next = newStart;
        
        return head;
        
    }
};