class ATM {
public:
    int n;
    vector<long> notes;
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
            if(amount>=500 && notes[i]>0 && i==4)
            {
                long cnt  = amount/500;
                long take = min(cnt ,notes[i]);
                
                ans[i] = take;
                notes[i] -= take;
                amount -= (take*500);
            }
            else if(amount>=200 && notes[i]>0 && i==3)
            {
                long cnt = amount/200;
                long take = min(cnt , notes[i]);
                
                ans[i] = take;
                notes[i] -= take;
                amount -= (take*200);
            }
            else if(amount>=100 && notes[i]>0 && i==2)
            {
                long cnt = amount/100;
                long take = min(cnt , notes[i]);
                
                ans[i] = take;
                notes[i] -= take;
                
                amount -= (take*100);
            }
            else if(amount>=50 && notes[i]>0 && i==1)
            {
                long cnt = amount/50;
                long take = min(cnt , notes[i]);
                
                ans[i] = take;
                notes[i] -= take;
                
                amount -= (take*50);
            }
            else if(amount>=20 && notes[i]>0 && i==0)
            {
                long cnt = amount/20;
                long take = min(cnt , notes[i]);
                
                ans[i] = take;
                notes[i] -= take;
                
                amount -= (take * 20);
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