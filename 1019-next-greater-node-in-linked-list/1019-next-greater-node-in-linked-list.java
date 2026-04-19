class Solution {
    public int[] nextLargerNodes(ListNode head) {
        
        // Step 1: find size
        int size = 0;
        ListNode temp = head;
        while (temp != null) {
            size++;
            temp = temp.next;
        }

        int[] res = new int[size];
        int k = 0;

        temp = head;

        // Step 2: your logic
        while (temp != null) {
            int m = temp.val;
            ListNode future = temp.next;

            while (future != null) {
                if (future.val > m) {
                    m = future.val;
                    break;
                }
                future = future.next;
            }

            // same idea as your m == temp.val
            if (m == temp.val) {
                res[k] = 0;
            } else {
                res[k] = m;
            }

            k++;
            temp = temp.next;
        }

        return res;
    }
}