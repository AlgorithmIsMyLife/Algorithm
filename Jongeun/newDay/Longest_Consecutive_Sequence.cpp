#include <iostream>

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int res{};
    unordered_set<int> us;

    for (int i = 0; i < nums.size(); i++) {
      us.insert(nums[i]);
    }

    for (int i = 0; i < nums.size(); i++) {
      if (us.find(nums[i] + 1) == us.end()) {
        int longnum = 1;
        int searchnum = nums[i] - 1;
        while (us.find(searchnum) != us.end()) {
          longnum++;
          searchnum--;
        }

        res = max(res, longnum);
      }
    }

    return res;
  }
};

int main() {}
