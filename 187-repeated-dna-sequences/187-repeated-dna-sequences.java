class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> ans = new ArrayList();
        
        int n = s.length();
        
        if(n<=10) return ans;
        
        //StringBuilder st = new StringBuilder("");
        String st="";
        Map<String,Integer> map = new HashMap();
        
        
        for(int i=0;i<n;i++)
        {
            if(i<9)
            {
                st+=s.charAt(i);
            }
            else
            {
               st+=s.charAt(i);
                if(map.containsKey(st) && map.get(st)==1){
                    ans.add(st.toString());
                }
                map.put(st,map.getOrDefault(st,0)+1); 
                int x=st.length();
                st=st.substring(1,x);
            }
        }
        
        
        System.out.println(map.size());
//         for (Map.Entry<StringBuilder,Integer> entry : map.entrySet())
//             System.out.println("Key = " + entry.getKey() +
//                              ", Value = " + entry.getValue());
        
        
        return ans;
        
    }
}