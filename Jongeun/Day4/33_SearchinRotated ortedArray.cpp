class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
            // not rotated
            if (nums[start] < nums[end])
            {
                int mid = (start + end) / 2;
                if (nums[mid] == target)
                {
                    return mid;
                }
                else if (target < nums[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                // rotated
                int mid = (start + end) / 2;
                if (nums[start] <= nums[mid])
                {
                    // mid positioned in left sorted part
                    if (target == nums[mid])
                    {
                        return mid;
                    }
                    else
                    {
                        if (target >= nums[start] && target < nums[mid])
                        {
                            end = mid - 1;
                        }
                        else
                        {
                            start = mid + 1;
                        }
                    }
                }
                else
                {
                    // mid positioned in the right sorted part
                    if (target == nums[mid])
                    {
                        return mid;
                    }
                    else
                    {
                        if (target > nums[mid] && target <= nums[end])
                        {
                            start = mid + 1;
                        }
                        else
                        {
                            end = mid - 1;
                        }
                    }
                }
            }
        }

        return -1;
    }
};
