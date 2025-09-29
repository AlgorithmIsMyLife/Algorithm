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
 * @return {TreeNode}
 */
var invertTree = function (root) {
  switchNode(root);
  return root;
};
function switchNode(node) {
  if (node === null) return;
  const tmp = node.left;
  node.left = node.right;
  node.right = tmp;

  switchNode(node.left);
  switchNode(node.right);
}
