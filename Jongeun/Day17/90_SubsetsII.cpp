class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> res;
        unordered_map<int, int> m;
        for (auto i : nums)
        {
            m[i]++;
        }

        vector<int> keys;
        int steps{};
        for (auto &i : m)
        {
            keys.push_back(i.first);
        }

        steps = keys.size();

        vector<int> powerSet;
        _subsetsWithDup(res, powerSet, m, keys, steps);
        return res;
    }

    void _subsetsWithDup(vector<vector<int>> &res, vector<int> &powerSet, unordered_map<int, int> &m, vector<int> &keys, int step)
    {
        if (step == 0)
        {
            res.push_back(powerSet);
            return;
        }

        for (int i = 0; i < m[keys[step - 1]] + 1; i++)
        {
            if (i == 0)
            {
                _subsetsWithDup(res, powerSet, m, keys, step - 1);
            }
            else
            {
                powerSet.push_back(keys[step - 1]);
                _subsetsWithDup(res, powerSet, m, keys, step - 1);
            }
        }

        for (int i = 0; i < m[keys[step - 1]]; i++)
        {
            powerSet.pop_back();
        }
    }
};
