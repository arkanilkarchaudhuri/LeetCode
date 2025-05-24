impl Solution {
  pub fn find_words_containing(words: Vec<String>, x: char) -> Vec<i32> {
    return words.iter()
        .enumerate()
        .filter_map(|(index, word)| word.contains(x).then(|| index as i32))
        .collect();
  }
}