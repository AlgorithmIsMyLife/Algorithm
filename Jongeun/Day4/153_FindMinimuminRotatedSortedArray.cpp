class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size() - 1;

        // return minimum if the size is 1
        if (end == 0)
        {
            return nums[end];
        }

        while ((end - start) > 1)
        {
            int mid = (start + end) / 2;
            int m = min(nums[start], nums[end]);

            // if min is less than both of start and end
            if (nums[mid] < m)
            {
                end = mid;
            }
            else
            {
                // min is equal or bigger
                if (nums[start] < nums[end])
                {
                    end = mid;
                }
                else
                {
                    start = mid;
                }
            }
        }

        if (nums[start] < nums[end])
        {
            return nums[start];
        }
        else
        {
            return nums[end];
        }
    }
};
