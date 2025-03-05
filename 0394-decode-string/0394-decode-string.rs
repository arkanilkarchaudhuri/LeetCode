impl Solution {
    pub fn decode_string(s: String) -> String {
	s
	.chars()
	.fold((String::new(), String::new(), Vec::new()), |(mut next_string, mut next_integer, mut stack): (String, String, Vec<(usize, String)>), c| {
		match c {
			'0'..='9' => {
				next_integer.push(c);
				(next_string, next_integer, stack)
			},
			'[' => {
				stack.push((next_integer.parse::<usize>().unwrap(), next_string));
				next_integer.clear();
				(String::new(), next_integer, stack)
			},
			']' => {
				let (last_integer, left_string) = stack.pop().unwrap();
				let next_string = left_string + &next_string.repeat(last_integer);
				(next_string, next_integer, stack)
			},
			c => {
				next_string.push(c);
				(next_string, next_integer, stack)
			}
		}
	}).0
}
}