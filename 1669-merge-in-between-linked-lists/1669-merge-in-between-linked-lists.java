class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode prev = list1;
        for (int i = 0; i < a - 1; i++) {
            prev = prev.next;
        }
        ListNode curr = list1;
        for (int i = 0; i <= b; i++) {
            curr = curr.next;
        }

        prev.next = list2;

        ListNode temp = list2;
        while (temp.next != null) {
            temp = temp.next;
        }

        temp.next = curr;

        return list1;
    }
}