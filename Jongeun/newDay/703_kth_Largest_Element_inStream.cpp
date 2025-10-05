#include <iostream>
#include <vector>

using namespace std;

class KthLargest {
public:
  KthLargest(int k, vector<int> &nums) : K(k) {

    for (int i = 0; i < nums.size(); i++) {
      minPq.push(nums[i]);
    }

    while (minPq.size() > K) {
      int temp = minPq.top();
      minPq.pop();
      maxPq.push(temp);
    }
  }

  int add(int val) {
    if (minPq.size() < K) {
      minPq.push(val);
      return minPq.top();
    }

    if (val > minPq.top()) {
      int temp = minPq.top();
      minPq.pop();
      maxPq.push(temp);
      minPq.push(val);
    } else {
      maxPq.push(val);
    }

    return minPq.top();
  }

  priority_queue<int, vector<int>, greater<int>> minPq;
  priority_queue<int> maxPq;
  int K;
};

int main() { Solution s{}; }
