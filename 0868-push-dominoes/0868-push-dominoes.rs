
impl Solution {
    pub fn push_dominoes(dominoes: String) -> String {
        let mut ste: Vec<i32> = vec![0; dominoes.len()];
        let mut curr: i32 = 0;
        for (idx, c) in dominoes.char_indices() {
            match c {
                'R' => curr = i32::MAX,
                'L' => curr = 0,
                _ => curr = i32::max(0, curr-1)
            }
            ste[idx] = curr
        }
        curr = 0;
        for (idx, c) in dominoes.char_indices().rev() {
            match c {
                'L' => curr = i32::MAX,
                'R' => curr = 0,
                _ => curr = i32::max(0, curr-1)
            }
            ste[idx] -= curr
        }
        ste.iter()
            .map(|&x| match x.cmp(&0) {
                Ordering::Less => 'L',
                Ordering::Greater => 'R',
                Ordering::Equal => '.',
            })
            .collect()
    }
}