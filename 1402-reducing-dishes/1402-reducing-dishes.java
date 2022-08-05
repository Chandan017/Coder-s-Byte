class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        
        Arrays.sort(satisfaction);

     int len=satisfaction.length;

     if(satisfaction[len-1]<=0) return 0;

     int max=satisfaction[len-1];

     int base=max;

     for(int i=len-2;i>=0;i--)

     {

         int next=satisfaction[i]+max+base;

         if(next>=max)

         {

             max=next;

             base+=satisfaction[i];

         }

         else

             return max;

     }
        
    return max;
        
    }
}