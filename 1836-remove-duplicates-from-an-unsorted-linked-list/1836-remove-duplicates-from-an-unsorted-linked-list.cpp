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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        
        unordered_map<int,int> mpp;
        ListNode* temp = head;
        
        while(temp)
        {
            mpp[temp->val]++;
            temp = temp->next;
        }
        
        ListNode* newHead = new ListNode(0);
        ListNode* dummy = newHead;
        temp = head;
        
        while(temp)
        {
            if(mpp[temp->val] == 1)
            {
                dummy->next = temp;
                dummy = dummy->next;
                temp = temp->next;

                dummy->next = NULL;
            }
            else
                temp = temp->next;
                
        }
        
        
        
        
        newHead = newHead->next;
        return newHead;
        
    }
};