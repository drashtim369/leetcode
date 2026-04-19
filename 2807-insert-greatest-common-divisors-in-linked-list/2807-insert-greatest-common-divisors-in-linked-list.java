/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if (head == null) return head;
        ListNode cur = head;
        while (cur.next != null) {
            int g = gcd(cur.val, cur.next.val);
            ListNode node = new ListNode(g);
            node.next = cur.next;
            cur.next = node;
            cur = node.next;
        }
        return head;
    }
    int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
}