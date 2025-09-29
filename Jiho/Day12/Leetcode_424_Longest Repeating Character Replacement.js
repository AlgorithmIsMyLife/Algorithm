// #1. DFS 이용하여 전역 탐색 (시간 초과)
var characterReplacement = function (s, k) {
  const set = new Set(s);
  const arr = s.split("");

  let max = 0;

  function findmaxLength(array, index, currentK) {
    // console.log("array: ", array, "index: ", index, "currentK: ", currentK);
    // #0. max 갱신
    max = Math.max(max, lengthOfLongestSubstring(array));
    // 끝내기
    if (currentK === k || index >= array.length) {
      // console.log("실행여부 탈락");

      return 0;
    }
    for (const val of set) {
      // #1. 안바뀌는 경우
      if (val === array[index]) {
        findmaxLength(array, index + 1, currentK);
      }
      // #2. 바꾸는 경우
      else {
        const new_array = [...array];
        new_array[index] = val;
        findmaxLength(new_array, index + 1, currentK + 1);
      }
    }
  }
  findmaxLength(arr, 0, 0);
  return max;
};

var lengthOfLongestSubstring = function (s) {
  const len = s.length;
  let max = 1;
  let char = s[0];
  let cnt = 1;
  for (let i = 1; i < len; i++) {
    if (s[i] === char) {
      cnt += 1;
      max = Math.max(cnt, max);
    } else {
      char = s[i];
      cnt = 1;
    }
  }
  return max;
};

// Time Complexity :  O(n)
// Space Complexity : O(1)
var characterReplacementSol = function (s, k) {
  var map = [26];

  let [largestCount, left, maxlen] = [0, 0, 0];

  for (let right = 0; right < s.length; right++) {
    const c = s[right];
    map[c] = (map[c] || 0) + 1;

    largestCount = Math.max(largestCount, map[c]);

    if (right - left + 1 - largestCount > k) {
      map[s[left]] -= 1;
      left += 1;
    }

    maxlen = Math.max(maxlen, right - left + 1);
  }
  return maxlen;
};

console.log(characterReplacementSol("ABAB", 2));
