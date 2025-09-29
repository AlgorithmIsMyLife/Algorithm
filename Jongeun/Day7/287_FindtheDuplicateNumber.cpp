#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[nums[0]];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = nums[0];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << obj.findDuplicate(nums) << endl;
    return 0;
}
