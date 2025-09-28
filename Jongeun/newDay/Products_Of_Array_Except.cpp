class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {

    vector<int> forwardPass(nums.size());
    vector<int> backwardPass(nums.size());

    for (int i = 0; i < nums.size(); i++) {
      if (i == 0) {
        forwardPass[i] = nums[i];
      } else {
        forwardPass[i] = forwardPass[i - 1] * nums[i];
      }
    }

    for (int i = nums.size() - 1; i >= 0; i--) {

      if (i == nums.size() - 1) {
        backwardPass[i] = nums[i];
      } else {
        backwardPass[i] = backwardPass[i + 1] * nums[i];
      }
    }

    vector<int> Result(nums.size());

    for (int i = 0; i < nums.size(); i++) {

      int forward = (i - 1 != -1 ? forwardPass[i - 1] : 1);
      int backward = (i + 1 != nums.size() ? backwardPass[i + 1] : 1);

      Result[i] = forward * backward;
    }

    return Result;
  }
};
