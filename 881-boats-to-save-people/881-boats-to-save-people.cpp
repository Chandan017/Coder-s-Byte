class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin() , people.end());
        
        int low=0 , high=people.size()-1;
        
        int cntBoats=0;
        while(low <=high)
        {
            // check pople with less wieghts and high weight both can travel
            // then take less wight people together else only high weight people
            if(people[low] + people[high] <=limit) 
                low++;
            
            high--;
            // increment no. of baots
            cntBoats++;
        }
        
        return cntBoats;
        
    }
};