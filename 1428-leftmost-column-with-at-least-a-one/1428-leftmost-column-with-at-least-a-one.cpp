/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        vector<int> dim = binaryMatrix.dimensions();
        
        int r = 0 , c = dim[1]-1;
        
        int ind = INT_MAX;
        // cout<<r<<" "<<c<<endl;
        while(c>=0 && r<dim[0])
        {
            // cout<<"a";
            int val = binaryMatrix.get(r , c);
            // cout<<val<<" ";
            if(val == 0)
                r++;
            else
            {
                ind = min(ind , c);
                c--;
            }
        }
        
        if(ind == INT_MAX)
            return -1;
        return ind;
        

    }
};