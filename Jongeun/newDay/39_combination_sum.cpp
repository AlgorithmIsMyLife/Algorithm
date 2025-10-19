#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &nums, int target) {
    vector<vector<int>> ret;
    vector<int> temp;
    backtrack(0, 0, target, temp, nums, ret);
    return ret;
  }

  void backtrack(int i, int subSum, int target, vector<int> &temp,
                 vector<int> &nums, vector<vector<int>> &ret) {
    if (subSum == target) {
      ret.push_back(temp);
      return;
    }

    if (subSum > target) {
      return;
    }

    for (; i < nums.size(); i++) {
      temp.push_back(nums[i]);
      backtrack(i, subSum + nums[i], target, temp, nums, ret);
      temp.pop_back();
    }
  }
};

int main() { Solutin s{}; }
