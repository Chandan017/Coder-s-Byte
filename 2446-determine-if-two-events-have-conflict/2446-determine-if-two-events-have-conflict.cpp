class Solution {
public:
    
    int getTime(string &s)
    {
        int hour = (s[0]-'0')*10 + (s[1]-'0');
        int minutes = (s[3]-'0')*10 + (s[4]-'0');
        
        int time = (hour*60) + minutes;
        
        return time;
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        
        
        pair<int,int> firstEvent = {getTime(event1[0]) , getTime(event1[1])};
        pair<int,int> secondEvent = {getTime(event2[0]) , getTime(event2[1])};
        
        // cout<<firstEvent.first<<"->"<<firstEvent.second<<"   "<<secondEvent.first<<"->"<<secondEvent.second<<endl;
        
        if((secondEvent.first <= firstEvent.second && secondEvent.first >= firstEvent.first) || (firstEvent.first <= secondEvent.second && firstEvent.first >= secondEvent.first))
            return true;
        
        return false;
        
    }
};