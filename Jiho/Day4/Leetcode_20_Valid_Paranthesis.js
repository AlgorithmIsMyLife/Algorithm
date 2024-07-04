var isValid = function (s) {
  const arr = s.split("");
  // #0. 예외: 홀수개
  if (arr.length % 2 === 1) return false;
  const stack = [];
  for (let i = 0; i < arr.length; i++) {
    // 열기
    if (arr[i] === "(" || arr[i] === "[" || arr[i] === "{") {
      stack.push(arr[i]);
      // console.log(stack);
    }
    // 닫기
    else {
      const topmost = stack.pop();
      // console.log(topmost);
      if (arr[i] === ")" && topmost != "(") {
        return false;
      }
      if (arr[i] === "}" && topmost != "{") {
        return false;
      }
      if (arr[i] === "]" && topmost != "[") {
        return false;
      }
    }
  }
  if (stack.length != 0) return false;
  return true;
};

console.log(isValid("(]"));
