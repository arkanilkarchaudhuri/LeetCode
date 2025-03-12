impl Solution {
    pub fn total_cost(costs: Vec<i32>, k: i32, candidates: i32) -> i64 {
        use std::{cmp::Reverse, collections::BinaryHeap};
        let mut costs = costs.into_iter();
        let candidates = candidates as usize;
        let mut heap =
            BinaryHeap::from_iter(costs.by_ref().take(candidates).map(|n| (Reverse(n), true)));
        heap.extend(
            costs
                .by_ref()
                .rev()
                .take(candidates)
                .map(|n| (Reverse(n), false)),
        );

        let mut ans = 0;
        (0..k).for_each(|_| {
            let (Reverse(n), is_front) = heap.pop().unwrap();
            ans += n as i64;

            if let Some(n) = if is_front {
                costs.next()
            } else {
                costs.next_back()
            } {
                heap.push((Reverse(n), is_front));
            }
        });
        ans
    }
}