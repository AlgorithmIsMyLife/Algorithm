// my sol.
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int sum = 0, l = 0, r = 0, tempt = 0;

        unordered_set<char> chars;

        while (r < s.size())
        {
            while (chars.find(s[r]) != chars.end())
            {
                chars.erase(s[l]);
                l++;
            }

            chars.insert(s[r]);
            sum = max(sum, r - l + 1);
            r++;
        }

        return sum;
    }
};
