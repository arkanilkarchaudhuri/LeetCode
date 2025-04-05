class Solution {
    private ListNode rec(ListNode head,int k)
    {
        if(head==null)
        return null;
        int c = k;
        ListNode curr = head,prev = null,next = null;
        while(curr!=null && c>0)
        {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
            c--;
        }
        if(c>0)
        {
            curr = prev;
            next = null;
            prev = null;
            while(curr!=null)
            {
                next = curr.next;
                curr.next = prev;
                prev = curr;
                curr = next;
            }
        }
        if(c>0) return prev;
        head.next = rec(curr,k);
        return prev;
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        return rec(head,k);
    }
}