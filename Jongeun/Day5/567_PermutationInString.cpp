class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> hash{};

        for (auto s : s1)
        {
            hash[s]++;
        }

        int l = 0, r = 0;

        while (r < s2.size())
        {
            if (hash.find(s2[r]) != hash.end())
            {
                // found
                if (hash[s2[r]] > 0)
                {
                    // not overflowed
                    hash[s2[r]]--;
                    r++;
                    if (r - l >= s1.size())
                    {
                        return true;
                    }
                }
                else
                {
                    // the count is overflowed
                    hash[s2[l]]++;
                    l++;
                }
            }
            else
            {
                r++;
                while (l < r)
                {
                    if (hash.find(s2[l]) != hash.end())
                    {
                        hash[s2[l]]++;
                    }
                    l++;
                }
            }
        }

        return false;
    }
};
