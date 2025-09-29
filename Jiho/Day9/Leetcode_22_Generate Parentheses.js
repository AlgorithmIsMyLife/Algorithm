var generateParenthesis = function (n) {
  const res = [];
  function dfs(opencnt, closecnt, s) {
    if (opencnt === closecnt && opencnt === n && closecnt === n) {
      res.push(s);
      return;
    }

    if (opencnt < n) {
      dfs(opencnt + 1, closecnt, s + "(");
    }

    if (opencnt > closecnt) {
      dfs(opencnt, closecnt + 1, s + ")");
    }
  }

  dfs(0, 0, "");
  return res;
};

console.log(generateParenthesis(3));
