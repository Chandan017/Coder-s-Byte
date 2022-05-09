class Solution {
public:
    unordered_map<int,vector<string>> mpp;
    vector<string> ans;
    
    void get(int num)
    {
        if(ans.size()==0)
        {
            for(auto it:mpp[num])
                ans.push_back(it);
       
        }
        else
        {
            int n=ans.size();
            vector<string> dummy;
            for(int i=0;i<n;i++)
            {
                
                for(auto it:mpp[num])
                {
                    dummy.push_back(ans[i]+it);
                }
            }
            
            ans=dummy;
            
        }
        
        return ;
    }
    
    
    
    vector<string> letterCombinations(string s) {
     
         mpp[2]={"a","b","c"};
         mpp[3]={"d","e","f"};
         mpp[4]={"g","h","i"};
         mpp[5]={"j","k","l"};
         mpp[6]={"m","n","o"};
         mpp[7]={"p","q","r","s"};
         mpp[8]={"t","u","v"};
         mpp[9]={"w","x","y","z"};
            
       for(int i=0;i<s.length();i++)
       {
           int num=s[i]-'0';
           
           get(num);
       }
             
        return ans;
        
        
    }
};