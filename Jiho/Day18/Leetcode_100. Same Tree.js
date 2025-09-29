// p,q are roots of two binary trees
var isSameTree = function (p, q) {
  // 두개다 null인 경우
  if (!p && !q) {
    return true;
  }
  // 둘다 null이 아닌 경우
  else if (!p !== null && q !== null) {
    if (p.val !== q.val) return false;

    if (
      (p.left !== null && q.left === null) ||
      (p.left === null && q.left !== null)
    ) {
      return false;
    }
    if (
      (p.right !== null && q.right === null) ||
      (p.right === null && q.right !== null)
    ) {
      return false;
    }
    return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
  }
  // 둘중 하나만 null인 경우
  else {
    return false;
  }
};

// p,q are roots of two binary trees
var isSameTree = function (p, q) {
  // #1. p and q are null
  if (!p && !q) {
    return true;
  }
  // #2. p and q should not have null + same value
  else if (!p || !q || p.val !== q.val) {
    return false;
  }
  // #3. Check left and right validation
  else {
    // 최적화 방법
    if (!isSameTree(p.left, q.left)) {
      return false;
    }
    return isSameTree(p.right, q.right);
    // return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
  }
};
