class Solution {
public:
    string removeDigit(string number, char digit) {
        
        int n = number.length();
        string maxNumber="";
        
        for(int i =0;i<n;i++)
        {
            if(number[i]==digit)
            {
                string temp = number;
                number.erase(number.begin()+i);
                
                if(maxNumber == "")
                    maxNumber = number;
                else if(number > maxNumber)
                    maxNumber = number;
                
                number = temp;
            }
        }
        
        return maxNumber;
        
    }
};