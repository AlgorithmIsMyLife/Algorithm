#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    vector<int> count(26, 0);
    for (char task : tasks) {
      count[task - 'A']++;
    }

    sort(count.begin(), count.end());
    int maxf = count[25];
    int idle = (maxf - 1) * n;

    for (int i = 24; i >= 0; i--) {
      idle -= min(maxf - 1, count[i]);
    }
    return max(0, idle) + tasks.size();
  }
};

int main() {

  Solution s{};
  vector<char> input{'A', 'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D',
                     'E', 'E', 'F', 'F', 'K', 'K', 'J', 'J'};
  s.leastInterval(input, 3);
}
