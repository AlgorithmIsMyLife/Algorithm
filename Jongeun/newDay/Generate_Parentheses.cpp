#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {

    string init = "";
    int step = 0;

    int openNum = 0;
    int closeNum = 0;

    vector<string> res{};

    _generate(n, step, openNum, closeNum, init, res);

    return res;
  }

  void _generate(int n, int step, int openNum, int closeNum, string &init,
                 vector<string> &res) {

    if (step == 2 * n) {
      res.push_back(init);
      return;
    }

    if (openNum < closeNum) {
      return;
    }

    if (openNum < n) {
      init.push_back('(');
      openNum++;
      _generate(n, step + 1, openNum, closeNum, init, res);
      init.pop_back();
      openNum--;
    }
    if (closeNum < n) {
      init.push_back(')');
      closeNum++;
      _generate(n, step + 1, openNum, closeNum, init, res);
      init.pop_back();
      closeNum--;
    }
  }
};

int main() {
  Solution s{};

  s.generateParenthesis(3);
}
