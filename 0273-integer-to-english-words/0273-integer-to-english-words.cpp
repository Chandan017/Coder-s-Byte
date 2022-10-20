class Solution {
public:
    vector<string> ones = {"Zero ","One " , "Two " , "Three " , "Four " , "Five " , "Six " , "Seven " , "Eight "  , "Nine "};
    vector<string> middle = {"Ten " , "Eleven " , "Twelve " , "Thirteen " , "Fourteen " , "Fifteen " , "Sixteen " , "Seventeen ","Eighteen ","Nineteen "};
    vector<string> tens = {"a" , "a" , "Twenty " , "Thirty " , "Forty " , "Fifty " , "Sixty " , "Seventy " , "Eighty " , "Ninety "};
    
    
    string solve(int num)
    {
        if(num >= 1000000000)
        {
            string res = solve(num/1000000000) + "Billion ";
            res += solve(num % 1000000000);
            
            return res;
        }
        else if(num >= 1000000)
        {
            string res = solve(num/1000000) + "Million ";
            res += solve(num % 1000000);
            
            return res;
        }
        else if(num >= 1000)
        {
            string res = solve(num/1000) + "Thousand ";
            res += solve(num%1000);
            return res;
        }
        else if(num >=100)
        {
            string res = solve(num/100) + "Hundred ";
            res += solve(num%100);
            
            return res;
        }
        else if(num >= 20)
        {
            string res = tens[(num/10)];
            res += solve(num%10);
            
            return res;
        }
        else if(num >= 10 && num<20)
        {
            string res = middle[(num%10)];
            return res;
        }
        else if(num >=1 )
            return ones[num%10];
        
        return "";
            
    }
    string numberToWords(int num) {
        
        if(num == 0)
            return "Zero";
        
        string res = solve(num);
        res.pop_back();
        
        return res;
        
    }
};