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
    
    
    vector<int> nextLargerNodes(ListNode* head) {
        
        ListNode* prevptr=NULL;
        ListNode* nextptr;
        ListNode* currptr=head;
        
        while(currptr)
        {
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
        }
        
        head=prevptr;
        stack<int> st;
        vector<int> ans;
        while(head)
        {
            while(st.size()>0 && st.top()<=head->val)
                st.pop();
            if(st.size()==0)
                ans.push_back(0);
            else
                ans.push_back(st.top());
            
            st.push(head->val);
            head=head->next;
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
        
        
    }
};