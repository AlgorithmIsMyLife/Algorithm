const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n");

function isValid(map) {
  for (let value of map.values()) {
    if (value > 0) return false;
  }
  return true;
}

var minWindow = function (s, t) {
  const set_t = new Map();
  for (let i = 0; i < t.length; i++) set_t.set(t[i], (set_t.get(t[i]) | 0) + 1);

  // #1. 맞는 처음 찾기
  let queue = [];
  let set = new Map(set_t.entries());
  for (let i = 0; i < s.length; i++) {
    if (set.has(s[i])) {
      queue.push(i);
      set.set(s[i], set.get(s[i]) - 1);
      if (isValid(set)) break;
    }
  }
  // 예외 처리
  if (!isValid(set)) return "";

  // #2. 최소값 찾기
  let [l, r] = [queue[0], queue[queue.length - 1]];
  let [min_l, min_r] = [l, r];
  while (queue.length != 0) {
    const left = s[queue.shift()]; // left를 r이 찾아줘야함
    set.set(left, set.get(left) + 1);
    l = queue[0];
    let first_r = r;
    while (r < s.length) {
      // queue에 원소 추가
      if (set_t.has(s[r]) && r !== first_r) {
        queue.push(r);
        set.set(s[r], set.get(s[r]) - 1);
      }
      // 검사
      if (isValid(set)) {
        if (r - l < min_r - min_l) {
          min_l = l;
          min_r = r;
        }
        break;
      }
      r++;
    }
  }

  return s.slice(min_l, min_r + 1);
};
const [str1, str2] = input;

console.log(minWindow(str1, str2));
