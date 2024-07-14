var lengthOfLongestSubstring = function (s) {
  const len = s.length;
  let stack = [];
  let max = 0;
  for (let i = 0; i < len; i++) {
    if (stack.includes(s[i])) {
      const idxOfAlpha = stack.indexOf(s[i]);
      for (let j = 0; j <= idxOfAlpha; j++) {
        stack.shift();
      }
    }
    stack.push(s[i]);
    max = Math.max(max, stack.length);
  }
  return max;
};

console.log(lengthOfLongestSubstring(""));
