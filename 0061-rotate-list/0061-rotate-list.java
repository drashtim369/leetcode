class Solution {
    public ListNode rotateRight(ListNode head, int k) {

        if (head == null || head.next == null || k == 0) return head;

        int cnt = 0;
        ListNode temp = head;

        // count length
        while (temp != null) {
            temp = temp.next;
            cnt++;
        }

        k = k % cnt;
        if (k == 0) return head;

        // go to last node
        temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }

        // make circular
        temp.next = head;

        // find new tail
        int steps = cnt - k;
        ListNode newTail = head;

        for (int i = 1; i < steps; i++) {
            newTail = newTail.next;
        }

        // break
        ListNode newHead = newTail.next;
        newTail.next = null;

        return newHead;
    }
}