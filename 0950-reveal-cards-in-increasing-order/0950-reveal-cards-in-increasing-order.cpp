class Solution {
public:
    
    void rotate(vector<int> &nums)
    {
        int n = nums.size();
        
        if(n == 0)
            return ;
        int first = nums[0];
        
        for(int i=0;i<n-1;i++)
        {
            nums[i] = nums[i+1];
        }
        
        nums[n-1] = first;
        
        return ;
    }
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        priority_queue<int> pq(deck.begin() , deck.end());
        
        vector<int> res;
        while(pq.size())
        {
            rotate(res);
            res.push_back(pq.top());
            pq.pop();
        }
        
        
        reverse(res.begin() , res.end());
        
        return res;
    }
};