#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int fast = nums[0];
    int slow = nums[0];

    slow = nums[slow];
    fast = nums[nums[fast]];

    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    slow = nums[0];

    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};

int main() { Solutin s{}; }
