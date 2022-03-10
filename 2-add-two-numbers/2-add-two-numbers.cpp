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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        int sum=0,carry=0;
        ListNode* ans=new ListNode(0);
        ListNode* temp=ans;
        
        while(l1 || l2 || carry)
        {
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            
            sum+=carry;
            
            carry=sum/10;
            sum%=10;
            
            ListNode* dummy=new ListNode(sum);
            temp->next=dummy;
            temp=temp->next;
            
            sum=0;
        }
        
        return ans->next;
        
    }
};