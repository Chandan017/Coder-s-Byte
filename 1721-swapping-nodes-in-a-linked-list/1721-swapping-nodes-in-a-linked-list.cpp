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
    
    int getLen(ListNode* head)
    {
        int len=0;
        while(head)
        {
            head=head->next;
            len++;
        }
        return len;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        
        int len=getLen(head);
        int ind=1;
        ListNode* firstNode , *secondNode , *temp=head;
        
        while(temp)
        {
            if(firstNode!=NULL && secondNode!=NULL)
                break;
            if(ind==k)
                firstNode=temp;
            if(ind==len-k+1)
                secondNode=temp;
            
            temp = temp->next;
            ind++;
        }
        
        swap(firstNode->val , secondNode->val);
        
        return head;
        
    }
};