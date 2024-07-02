class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> map;
        int l = 0, r = 0, sum = 0;
        int maxf = 0;

        map[s[r]]++;
        maxf++;

        while (r < s.size())
        {
            // if valid
            // length - maxf
            if ((r - l + 1 - maxf) <= k)
            {
                sum = max(sum, r - l + 1);
                r++;
                map[s[r]]++;
                maxf = max(maxf, map[s[r]]);
            }
            else
            {
                while ((r - l + 1 - maxf) > k)
                {
                    map[s[l]]--;
                    l++;
                }
            }
        }
        return sum;
    }
};
