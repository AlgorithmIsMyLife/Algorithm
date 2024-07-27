class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int l = 0;
        int r = 0;
        int maxVal = INT_MIN;
        int tempMax = 0;
        while (r != nums.size())
        {
            tempMax += nums[r];
            maxVal = max(maxVal, tempMax);

            if (tempMax >= 0)
            {
                r++;
            }
            else
            {
                r++;
                while (l != r)
                {
                    tempMax -= nums[l];
                    l++;
                }
            }
        }

        return maxVal;
    }
};
