class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        vector<int> month = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        for(int i=1;i<month.size();i++)
        {
            month[i] += month[i-1];
        }        

        int aStart = month[stoi(arriveAlice.substr(0,2))-1] + stoi(arriveAlice.substr(3,2)) , aEnd = month[stoi(leaveAlice.substr(0,2))-1] + stoi(leaveAlice.substr(3,2)) , bStart = month[stoi(arriveBob.substr(0,2))-1] + stoi(arriveBob.substr(3,2)) , bEnd = month[stoi(leaveBob.substr(0,2))-1] + stoi(leaveBob.substr(3,2));
        
      
        
        int cnt = 0;
        
        set<int> st;
        
        while(aStart <= aEnd)
        {
            st.insert(aStart);
            aStart++;
        }
        
        while(bStart <= bEnd)
        {
            if(st.find(bStart) != st.end())
            {
                cnt++;
            }
            
            bStart++;
        }
        
        return cnt;
      
        
      
        
        
    }
};