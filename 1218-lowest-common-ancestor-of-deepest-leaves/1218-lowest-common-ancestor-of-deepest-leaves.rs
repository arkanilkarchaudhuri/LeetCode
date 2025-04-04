// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn lca_deepest_leaves(
        root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let mut level = 0;
        Self::dfs_helper(root, &mut level)
    }

    fn dfs_helper(
        root: Option<Rc<RefCell<TreeNode>>>,
        level: &mut i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        match root {
            None => None,
            Some(root) => {
                let mut ll = *level;
                let mut rl = *level;

                let left = Self::dfs_helper(root.borrow().left.clone(), &mut ll);
                let right = Self::dfs_helper(root.borrow().right.clone(), &mut rl);

                match ll.cmp(&rl) {
                    std::cmp::Ordering::Less => {
                        *level = rl + 1;
                        right
                    }
                    std::cmp::Ordering::Greater => {
                        *level = ll + 1;
                        left
                    }
                    std::cmp::Ordering::Equal => {
                        *level = ll + 1;
                        Some(root)
                    }
                }
            }
        }
    }
}