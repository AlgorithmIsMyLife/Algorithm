class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int l = 0;
        int maxIndex = 0;

        while (l < nums.size() - 1)
        {
            maxIndex = max(maxIndex, l + nums[l]);
            if (maxIndex >= nums.size() - 1)
            {
                return true;
            }

            if (l == maxIndex)
            {
                return false;
            }

            l++;
        }

        return true;
    }
};
