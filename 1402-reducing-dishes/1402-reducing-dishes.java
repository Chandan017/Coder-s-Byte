class Solution {
    public int maxSatisfaction(int[] input2) {
        int input1 = input2.length;
        
        Arrays.sort(input2);
        if(input2[input1-1] <= 0){
            return 0;
        }
        
        int res = 0;
        int beforeSum = 0;
        for(int i = input1-1; i>=0; i--){
            int currNum = input2[i];
            beforeSum += currNum;
            if(beforeSum >= 0){
            	res += beforeSum;
            }else{
                return res;
            }
        }
        
        return res;
        
    }
}