class Solution {
public:
    
    
    void rotate(vector<int> &nums)
    {
        int n = nums.size();
        
        if(n == 0)
            return ;
        int last = nums[n-1];
        
        for(int i=n-1;i>0;i--)
        {
            nums[i] = nums[i-1];
        }
        
        nums[0] = last;
        
        return ;
    }
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        priority_queue<int> pq(deck.begin() , deck.end());
        
        vector<int> res;
        while(pq.size())
        {
            rotate(res);
            res.insert(res.begin() , pq.top());
            pq.pop();
        }
        
        return res;
    }
};