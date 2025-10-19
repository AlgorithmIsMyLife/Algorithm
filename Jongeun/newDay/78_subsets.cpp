#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ret;
    vector<int> temp;
    int i = 0;
    backtrack(i, nums, temp, ret);

    return ret;
  }

  void backtrack(int i, vector<int> &nums, vector<int> &temp,
                 vector<vector<int>> &ret) {

    if (i == nums.size()) {
      ret.push_back(temp);
      return;
    }

    backtrack(i + 1, nums, temp, ret);
    temp.push_back(nums[i]);
    backtrack(i + 1, nums, temp, ret);
    temp.pop_back();
  }
};

int main() { Solutin s{}; }
