class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        vector<int> record;
        int totalSum = 0;
        for(auto it:ops)
        {
            if(it=="C")
            {
                totalSum -= record.back();
                record.pop_back();
            }
            else if(it=="D")
            {
                int prev = record.back();
                record.push_back(prev*2);
                
                totalSum += (prev*2);
            }
            else if(it=="+")
            {
                int firstPrev = record[record.size()-1];
                int secondPrev = record[record.size()-2];
                
                record.push_back(firstPrev + secondPrev);
                totalSum += (firstPrev + secondPrev);
            }
            else
            {
                int num = stoi(it);
                
                record.push_back(num);
                
                totalSum += num;
            }
        }
        
       
        
        return totalSum;
    }
};