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
        int n=0;
        while(currptr)
        {
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
            n++;
        }
        
        head=prevptr;
        stack<int> st;
        vector<int> ans(n,0);
        int currInd=0;
        while(head)
        {
            while(st.size()>0 && st.top()<=head->val)
                st.pop();
            if(st.size() > 0)
                ans[n-currInd-1] =st.top();
            
            st.push(head->val);
            head=head->next;
            currInd++;
        }
        return ans;
        
        
    }
};