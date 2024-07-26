console.log(...[1, 2, 3]);
console.log(new Map([1, 2, 3]));

console.log(isIdentical(new Set([1, 2, 3]), new Set([3, 1, 2])));

function isIdentical(setA, setB) {
  if (setA.size !== setB.size) {
    return false;
  }
  for (let elem of setA) {
    if (!setB.has(elem)) {
      return false;
    }
  }
  return true;
}
