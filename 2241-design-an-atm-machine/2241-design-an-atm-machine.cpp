class ATM {
public:
    int n;
    vector<long> notes;
    vector<int> denomination = {20,50,100,200,500};
    ATM() {
        
        n=5;
        
        for(int i=0;i<n;i++)
            notes.push_back(0);
        
        
    }
    
    void deposit(vector<int> banknotesCount) {
        
        for(int i=0;i<n;i++)
        {
            notes[i] += banknotesCount[i];
        }
        
        return ;
    }
    
    vector<int> withdraw(int amount) {
       
        vector<int> ans(5,0);
        
        for(int i=n-1;i>=0;i--)
        {
            if(amount>=denomination[i] && notes[i]>0 )
            {
                long cnt  = amount/denomination[i];
                long take = min(cnt ,notes[i]);
                
                ans[i] = take;
                notes[i] -= take;
                amount -= (take*denomination[i]);
            }
           
        }
        if(amount==0)
            return ans;
        else
        {
            for(int i=0;i<n;i++)
                notes[i] += ans[i];
            
            return {-1};
        }
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */