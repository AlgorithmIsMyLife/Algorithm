// 왼쪽깊이 구하기 + 오른쪽깊이 구하기

var isBalanced = function (root) {
  if (!root) {
    return true;
  }

  // #1. 자신
  let l = countNodes(root.left);
  let r = countNodes(root.right);

  if (Math.abs(l - r) > 1) {
    return false;
  }
  // #2. 왼쪽 오른쪽
  return isBalanced(root.left) && isBalanced(root.right);
};

const countNodes = (root, depth = 1) => {
  if (!root) {
    return 0;
  }

  if (!root.left && !root.right) {
    return depth;
  }

  return Math.max(
    countNodes(root.left, depth + 1),
    countNodes(root.right, depth + 1)
  );
};
