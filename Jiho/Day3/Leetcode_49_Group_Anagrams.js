const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split(" ");

// #1. 내 풀이
// s: string, t: string
var isAnagram = function (s, t) {
  if (s.length != t.length) return false;
  // #1. 저장 배열
  const arr = new Array(26).fill(0);
  // s: 원본 문자열
  const charstr = s.split("");

  for (const char of charstr) {
    const idx = char.charCodeAt() - 97;
    arr[idx] += 1;
  }
  // t: 테스트할 문자열
  const inputstr = t.split("");
  for (const char of inputstr) {
    const idx = char.charCodeAt() - 97;
    if (arr[idx] > 0) {
      arr[idx] -= 1;
    } else {
      return false;
    }
  }
  // #2. 남아있는거 있음?
  let i = 0;
  for (i; i < 26; i++) {
    if (arr[i] != 0) return false;
  }
  return true;
};

var groupAnagrams = function (strs) {
  let arr = [];
  let isEmptyExist = false;
  for (const str of strs) {
    console.log(str);
    if (str.length === 0 && !isEmptyExist) {
      arr.push([""]);
      isEmptyExist = true;
      continue;
    }
    let flag = false;
    for (let i = 0; i < arr.length; i++) {
      if (isAnagram(str, arr[i][0]) === true) {
        arr[i].push(str);
        flag = true;
        break;
      }
    }
    if (!flag) arr.push([str]);
    // console.log(arr);
  }
  return arr;
};
// #2. 정답 풀이 (객체를 활용!!!)
// 문제 조건 주시 : 같은 문자는 중복되어 나오지 않음!
var answer_groupAnagrams = function (strs) {
  let obj = {},
    result = [];
  for (let i = 0; i < strs.length; i++) {
    let str = strs[i];
    let sorted = str.split("").sort().join("");
    if (!obj[sorted]) {
      obj[sorted] = [str];
    } else {
      obj[sorted].push(str);
    }
  }

  for (let keys in obj) {
    result.push(obj[keys]);
  }

  return result;
};

console.log(answer_groupAnagrams(input));
