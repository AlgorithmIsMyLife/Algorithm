class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int first = 0, second = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int tempt = first;
            first = second;
            second = max(second, tempt + nums[i]);
        }

        return second;
    }
};
