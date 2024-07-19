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
  if (root === null) return 0;
  return getDepth(root);
};

function getDepth(node) {
  // #1. 마지막에 도착했을 때
  if (node.left === null && node.right === null) {
    return 1;
  }
  // #2. 마지막이 아닐 때
  const leftDepth = node.left === null ? 0 : 1 + getDepth(node.left);
  const rightDepth = node.right === null ? 0 : 1 + getDepth(node.right);
  return Math.max(leftDepth, rightDepth);
}
