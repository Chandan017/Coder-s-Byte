class Solution {
public:
    string intToRoman(int num) {
        
        
        string s="";
        
        while(num!=0)
        {
            if(num < 5)
            {
                if(num==4)
                {
                    s+="IV";
                    num-=4;
                }
                    
                else
                {
                    while(num!=0)
                    {
                        s+='I';
                        num--;
                    }
                }
            }
            else if(num < 10 && num>=5)
            {
                if(num>=9)
                {
                     s+="IX";
                    num-=9;
                }
                   
                
                else
                {
                    s+='V';
                    num-=5;
                }
                
            }
            else if(num <50 && num>=10)
            {
                if(num>=40)
                {
                    s+="XL";
                    num-=40;
                }
                else
                {
                    int temp=num/10;
                    while(temp--)
                    {
                        s+='X';
                    }
                    num%=10;
                }
                    
                
            }
            else if(num <100  && num>=50)
            {
                if(num>=90)
                {
                    s+="XC";
                    num-=90;
                }
                else
                {
                    int temp=num/50;
                    while(temp--)
                        s+='L';
                    num%=50;
                }
            }
            else if(num < 500 && num>=100)
            {
                if(num>=400)
                {
                    s+="CD";
                    num-=400;
                }
                else
                {
                    int temp=num/100;
                    while(temp--)
                        s+='C';
                    num%=100;
                }
            }
            else if(num < 1000 && num>=500)
            {
                if(num>=900)
                {
                    s+="CM";
                    num-=900;
                }
                else
                {
                    int temp=num/500;
                    while(temp--)
                        s+='D';
                    num%=500;
                }
            }
            else if(num>=1000)
            {
                int temp=num/1000;
                while(temp--)
                    s+='M';
                num%=1000;
            }
            
            cout<<num<<" ";
            
        }
        cout<<endl;
        
        return s;
    }
};