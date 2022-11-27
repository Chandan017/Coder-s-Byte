class Solution {
public:
    int pivotInteger(int n) {
        
        int sum = (n*(n+1)) / 2;
        
        int x = 1;
        // cout<<sum<<"-> ";
        while(x<=n)
        {
            int curr =(x*(x+1))/2;
            // cout<<curr<<"->";
            // cout<<(sum - curr + x)<<"  ";
            if(curr == (sum - curr + x))
                return x;
            x++;
        }
        
        // cout<<endl;
        
        return -1;
    }
};