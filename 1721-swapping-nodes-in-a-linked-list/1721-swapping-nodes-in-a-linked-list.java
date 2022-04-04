class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        int n = 0;
        
        ListNode h1 = head;
        
        while(h1 != null){
            n++;
            h1 = h1.next;
        }
        
        h1 = head;
        int curr;
        int k1 = k;
        
        while(k1-->1)
            h1 = h1.next;
        
        curr = h1.val;
        
        h1 = head;
        
        k1 = k;
        
        int temp;
        
        k1 = n-k1+1;
        
        while(k1-->1){
            h1 = h1.next;
        }
        
        temp = h1.val;
        h1.val = curr;
        
        k1 = k;
        h1 = head;
        
        while(k-->1)
            h1 = h1.next;
        
        h1.val = temp;
        
        
        return head;
    }
}