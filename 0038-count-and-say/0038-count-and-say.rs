impl Solution {
    pub fn RLE(input: &str) -> String {
        let chars: Vec<char> = input.chars().collect();
        let mut i = 0;
        let mut res = String::new();

        while i < chars.len() {
            let mut occ = 1;
            while i + 1 < chars.len() && chars[i] == chars[i + 1] {
                occ += 1;
                i += 1;
            }
            res.push_str(&occ.to_string());
            res.push(chars[i]);
            i += 1;
        }

        res
    }

    pub fn count_and_say(n: i32) -> String {
        let mut num = "1".to_string(); 

        for _ in 1..n { 
            num = Self::RLE(&num);
        }
        num
    }
}