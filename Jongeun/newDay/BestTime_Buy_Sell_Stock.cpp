#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int ret{0};
    int l = 0, r = 1;
    while (r < prices.size() && l < prices.size()) {
      if (prices[r] > prices[l]) {
        ret = max(ret, prices[r] - prices[l]);
      } else {
        l = r;
      }

      r++;
    }

    return ret;
  }
};

int main() { Solutin s{}; }
