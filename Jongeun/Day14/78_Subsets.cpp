class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<vector<int>> subsets;
        vector<int> subset;
        _subset(0, subset, nums, subsets);

        return subsets;
    }

    void _subset(int i, vector<int> num, vector<int> &nums, vector<vector<int>> &subsets)
    {
        if (i == nums.size())
        {
            subsets.push_back(num);
            return;
        }

        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                _subset(i + 1, num, nums, subsets);
            }
            else
            {
                num.push_back(nums[i]);
                _subset(i + 1, num, nums, subsets);
            }
        }
    }
};
