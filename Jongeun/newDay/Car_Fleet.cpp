#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {

    vector<pair<int, int>> cars; // position , speeed

    for (int i = 0; i < position.size(); i++) {
      cars.push_back({position[i], speed[i]});
    }

    sort(cars.begin(), cars.end(), greater<pair<int, int>>());

    stack<double> stk;

    for (int i = 0; i < cars.size(); i++) {
      double pos = cars[i].first;
      int speed = cars[i].second;
      double time = (target - pos) / speed;

      if (stk.empty() || stk.top() < time) {
        stk.push(time);
      }
    }

    return stk.size();
  }
};

int main() {
  Solution s{};
  vector<int> position{8, 12, 16, 11, 7};
  vector<int> speed{6, 9, 10, 9, 7};
  s.carFleet(17, position, speed);
}
