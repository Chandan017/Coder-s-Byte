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
    ListNode* removeNodes(ListNode* head) {
        
        vector<int> nums;
        
        while(head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        
        vector<int> res;
        int maxi = nums[nums.size()-1];
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i] >= maxi)
                res.push_back(nums[i]);
            
            maxi = max(maxi , nums[i]);
        }
        
        reverse(res.begin() , res.end());
        
        ListNode* newHead = new ListNode(res[0]);
        ListNode* temp = newHead;
        
        for(int i=1;i<res.size();i++)
        {
            temp->next = new ListNode(res[i]);
            temp = temp->next;
        }
        
        return newHead;
        
    }
};