var findMedianSortedArrays = function (nums1, nums2) {
  let arr = [...nums1, ...nums2];
  arr.sort((a, b) => a - b);
  const len = arr.length;
  // 홀수
  if (len % 2) {
    return arr[Math.floor(len / 2)];
  }
  // 짝수
  else {
    const mid = Math.floor(len / 2);
    return (arr[mid] + arr[mid - 1]) / 2;
  }
};

console.log(findMedianSortedArrays([1, 3], [2, 4, 5]));
