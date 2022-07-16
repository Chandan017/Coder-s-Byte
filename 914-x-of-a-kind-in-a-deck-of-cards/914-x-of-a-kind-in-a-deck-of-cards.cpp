class Solution {
public:
    int gcd(int n1 , int n2)
{
    if(n1==0)
        return n2;
    
    return gcd(n2%n1 , n1);
}
    bool hasGroupsSizeX(vector<int>& deck) {
        


    unordered_map<int,int> mpp;
    int val = 0;

    for(auto it:deck)
        mpp[it]++;

    for(auto it:mpp)
    {
        val = gcd(val , it.second);
        if(val <= 1)
            return 0;           

    }

    return 1;
    

   


    }
};