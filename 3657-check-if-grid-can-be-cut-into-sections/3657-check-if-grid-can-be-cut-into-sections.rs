impl Solution {
    pub fn check_valid_cuts(n: i32, rectangles: Vec<Vec<i32>>) -> bool {
        let mut horiz = Vec::with_capacity(rectangles.len());
        let mut verti = Vec::with_capacity(rectangles.len());
        for rectangle in rectangles {
            let [x0, y0, x1, y1] = rectangle[..] else { unreachable!() };
            horiz.push((x0, x1));
            verti.push((y0, y1));
        }

        let can_cut = |spans: &mut [(i32, i32)]| {
            const REQUIRED_CUTS: usize = 2;
            spans.sort_unstable();
            let mut end = spans[0].1;
            let mut cuts = 0;
            for (a, b) in spans {
                if *a >= end {
                    cuts += 1;
                    if cuts >= REQUIRED_CUTS {
                        return true
                    }
                }
                end = end.max(*b);
            }
            false
        };

        can_cut(&mut horiz) || can_cut(&mut verti)
    }
}