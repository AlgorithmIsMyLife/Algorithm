#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    int numZero = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      m[nums[i]]++;
    }

    // 경우의 수
    //  (0,0,0)
    //  (음,0, 양)
    //  (음,음,양)
    //  (양,양,음)

    // first  (0,0,0)
    vector<vector<int>> result;

    if (m[0] >= 3) {
      result.push_back({0, 0, 0});
    }

    // second  (음, 0, 양)
    if (m[0] >= 1) {
      int i = 0;
      int cur = nums[i];

      while (cur < 0) {
        if (m.find(cur * -1) != m.end()) {
          result.push_back({cur, 0, -1 * cur});
        }

        while (nums[i] == cur) {
          i++;
        }

        cur = nums[i];
      }
    }

    // third (음,음,양)
    int a = 0, b = 1;
    while (nums[a] < 0) {
      while (nums[b] < 0) {
        int temp = (nums[a] + nums[b]) * -1;

        if (m.find(temp) != m.end()) {
          result.push_back({nums[a], nums[b], temp});
        }

        int bPre = nums[b];

        while (nums[b] == bPre) {
          b++;
        }
      }

      int aPre = nums[a];
      while (nums[a] == aPre) {
        a++;
      }
      b = a + 1;
    }

    // fourth (양,양,음)
    a = nums.size() - 1;
    b = a - 1;
    while (nums[a] > 0) {
      while (nums[b] > 0) {
        int temp = (nums[a] + nums[b]) * -1;

        if (m.find(temp) != m.end()) {
          result.push_back({temp, nums[b], nums[a]});
        }

        int bPre = nums[b];

        while (nums[b] == bPre) {
          b--;
        }
      }

      int aPre = nums[a];
      while (nums[a] == aPre) {
        a--;
      }
      b = a - 1;
    }

    return result;
  }
};

int main() {
  Solution s{};
  vector<int> input{-1, 0, 1, 2, -1, 4};
  auto ret = s.threeSum(input);

  for (int i = 0; i < ret.size(); i++) {
    for (int j = 0; j < 3; j++) {
      cout << ret[i][j] << '\n';
    }
  }
}
