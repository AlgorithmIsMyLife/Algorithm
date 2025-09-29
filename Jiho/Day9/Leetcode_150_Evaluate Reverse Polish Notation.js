var evalRPN = function (tokens) {
  const stack = [];
  const token_arr = ["+", "-", "*", "/"];
  tokens.forEach((token) => {
    // 연산자
    if (token_arr.includes(token)) {
      // 순서 n2 n1
      const [n1, n2] = [stack.pop(), stack.pop()];
      switch (token) {
        case "+":
          stack.push(n1 + n2);
          break;
        case "-":
          stack.push(n2 - n1);
          break;
        case "*":
          stack.push(n2 * n1);
          break;
        case "/":
          stack.push(Math.trunc(n2 / n1));
          break;
      }
    }
    // 숫자
    else {
      stack.push(parseInt(token));
    }
  });
  return stack[0];
};

console.log(
  evalRPN(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"])
);
