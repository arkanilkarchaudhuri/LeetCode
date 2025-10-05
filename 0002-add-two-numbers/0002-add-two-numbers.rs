impl Solution {
    pub fn add_two_numbers(mut l1: Option<Box<ListNode>>, mut l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut carry = 0;
        let mut head = Box::new(ListNode::new(0));
        let mut tail = &mut head;
        while (l1 != None || l2 != None || carry != 0) { 
            let val = match l1 {
                Some(n) => {l1=n.next; n.val},
                None => 0
            } + match l2 {
                Some(n) => {l2=n.next; n.val},
                None => 0
            } + carry;
            carry = val / 10;
            tail.next = Some(Box::new(ListNode::new(val%10)));
            tail = tail.next.as_mut().unwrap();
        }
        head.next
    }
}