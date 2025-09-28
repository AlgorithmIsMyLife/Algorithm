#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int maxVal = *max_element(piles.begin(), piles.end());

    int lb = 0;
    int ub = maxVal + 1;

    while (lb + 1 < ub) {
      int mid = (lb + ub) / 2;
      if (!check(mid, h, piles)) {
        lb = mid;
      } else {
        ub = mid;
      }
    }

    return ub;
  }

  bool check(int r, int h, vector<int> &piles) {
    int hour{0};

    for (int i = 0; i < piles.size(); i++) {
      hour += (int)ceil(piles[i] / (double)r);
    }
    return (hour <= h);
  }
};

int main() {
  Solution s{};
  vector<int> input{25, 10, 23, 4};
  s.minEatingSpeed(input, 4);
}
