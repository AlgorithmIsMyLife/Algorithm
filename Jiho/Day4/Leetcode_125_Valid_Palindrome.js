var isPalindrome = function (s) {
  const arr = s
    .split("")
    .map((elm) => elm.toLowerCase())
    .filter((t) => (t >= "a" && t <= "z") || (t >= "0" && t <= "9"));

  // 정답 풀이 : RegEx 사용(필요할때 찾아서 사용하자)
  // let str = s.replace(/[^a-zA-Z0-9 ]/g, "").replace(/\s+/g, '');
  let left = 0,
    right = arr.length - 1;
  while (left <= right) {
    if (arr[left] != arr[right]) {
      return false;
    }
    left += 1;
    right -= 1;
  }
  return true;
};

console.log(isPalindrome("090"));
