class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) return head;
        ListNode temp = head; int cnt = 0;
        while (temp != null) {
            cnt++;
            temp = temp.next;
        }
        temp = head;
        k = k % cnt; if (k == 0) return head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = head;
        int steps = cnt - k;
        ListNode tail = head;
        for (int i = 1; i < steps; i++) {
            tail = tail.next;
        }
        ListNode newHead = tail.next;
        tail.next = null;
        return newHead;
    }
}