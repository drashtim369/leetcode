class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {

        ListNode dummy = new ListNode(-1);
        ListNode temp = dummy.next;

        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                temp = list1;
                list1 = list1.next;
            } else {
                temp = list2;
                list2 = list2.next;
            }
            temp = temp.next;
        }

        // attach remaining
        if (list1 != null) {
            temp.next = list1;
        } else {
            temp.next = list2;
        }

        return temp;
    }
}