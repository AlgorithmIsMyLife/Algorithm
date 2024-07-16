/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function (root) {
  getDepth(root);
};

function getDepth(node) {
  // #1. 마지막에 도착했을 때
  if (node.left === null && node.right === null) {
    return 1;
  }
  // #2. 마지막이 아닐 때
  let leftDepth = node.left === null ? 0 : 1 + getDepth(node.left);
  let rightDepth = node.right === null ? 0 : 1 + getDepth(node.right);
  console.log(
    "Node :",
    node,
    "에서의 max depth: ",
    Math.max(leftDepth, rightDepth)
  );
  return Math.max(leftDepth, rightDepth);
}
