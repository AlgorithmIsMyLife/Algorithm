#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    unordered_map<char, int> um;

    for (int i = 0; i < tasks.size(); i++) {
      um[tasks[i]]++;
    }

    priority_queue<int> pq;
    for (auto &it : um) {
      pq.push(it.second);
    }

    int time = 1;
    queue<pair<int, int>> q;
    int input = pq.top();
    pq.pop();
    q.push({time, input});

    while (!q.empty()) {
      time++;

      while (!q.empty() && ((time - q.front().first) > n)) {
        int rest = q.front().second - 1;
        q.pop();

        if (rest > 0) {
          pq.push(rest);
        }
      }

      if (!pq.empty()) {
        input = pq.top();
        pq.pop();
        q.push({time, input});
      }
    }

    return time;
  }
};

int main() {

  Solution s{};
  vector<char> input{'X', 'X', 'Y', 'Y'};
  s.leastInterval(input, 2);
}
