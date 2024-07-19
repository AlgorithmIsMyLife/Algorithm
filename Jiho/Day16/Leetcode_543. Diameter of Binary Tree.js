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
var diameterOfBinaryTree = function (root) {
  let max = 0;
  function getMaxDiameter(node) {
    // #1. 마지막에 도착했을 때
    if (node.left === null && node.right === null) {
      return 0;
    }
    // #2. 마지막이 아닐 때
    const leftDiameter = node.left === null ? 0 : 1 + getMaxDiameter(node.left);
    const rightDiameter =
      node.right === null ? 0 : 1 + getMaxDiameter(node.right);
    const diameter = leftDiameter + rightDiameter;
    max = Math.max(diameter, max);
    return Math.max(leftDiameter, rightDiameter);
  }
  getMaxDiameter(root);
  return max;
};
