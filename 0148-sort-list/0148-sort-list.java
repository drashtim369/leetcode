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
    public ListNode split(ListNode head) {
        ListNode slow = head, fast = head, prev = null;
        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode temp = slow;
        if (prev != null) {
            prev.next = null;
        }
        return temp;
    }
    public ListNode merge(ListNode first, ListNode second) {
        if (first == null) return second;
        if (second == null) return first;
        if (first.val < second.val) {
            first.next = merge(first.next, second);
            return first;
        } else {
            second.next = merge(first, second.next);
            return second;
        }
    }
    public ListNode sortList(ListNode head) {
         if (head == null || head.next == null) {
            return head;
        }
        ListNode temp = split(head);
        head = sortList(head);
        temp = sortList(temp);
        return merge(head,temp);
    }
}