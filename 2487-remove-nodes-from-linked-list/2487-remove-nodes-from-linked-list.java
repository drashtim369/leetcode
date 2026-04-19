class Solution {
    public ListNode removeNodes(ListNode head) {
        // Step 1: reverse
        head = reverse(head);
        
        int max = head.val;
        ListNode curr = head;
        
        // Step 2: remove smaller nodes
        while (curr.next != null) {
            if (curr.next.val < max) {
                curr.next = curr.next.next; // delete
            } else {
                curr = curr.next;
                max = curr.val;
            }
        }
        
        // Step 3: reverse again
        return reverse(head);
    }
    
    private ListNode reverse(ListNode head) {
        ListNode prev = null;
        
        while (head != null) {
            ListNode next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
}