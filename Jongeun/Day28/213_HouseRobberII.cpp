class Solution
{
public:
    int rob(vector<int> &nums)
    {

        if (nums.size() == 1)
        {
            return nums[0];
        }

        int first = 0, second1 = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {

            int tempt = first;
            first = second1;
            second1 = max(tempt + nums[i], second1);
        }

        first = 0;
        int second2 = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            int tempt = first;
            first = second2;
            second2 = max(tempt + nums[i], second2);
        }

        return max(second1, second2);
    }
};
