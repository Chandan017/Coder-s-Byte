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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* firstNode , *secondNode , *temp=head;
        
        int ind=1;
        while(temp && ind!=k)
        {
            temp=temp->next;
            ind++;
        }
        
        firstNode=temp;
        secondNode=head;
        
        while(temp->next)
        {
            temp=temp->next;
            secondNode=secondNode->next;
        }
        
        swap(firstNode->val , secondNode->val);
        
        return head;
            
        
    }
};