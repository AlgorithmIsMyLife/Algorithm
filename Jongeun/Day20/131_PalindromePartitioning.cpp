class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> sub;
        _partition(res, sub, s);
        return res;
    }

    void _partition(vector<vector<string>> &res, vector<string> &sub, string s)
    {
        if (isPalindrom(s))
        {
            sub.push_back(s);
            res.push_back(sub);
            sub.pop_back();
        }

        for (int i = 0; i < s.size() - 1; i++)
        {
            string left = s.substr(0, i + 1);
            if (isPalindrom(left))
            {
                sub.push_back(left);
                _partition(res, sub, s.substr(i + 1));
                sub.pop_back();
            }
        }
    }

    bool isPalindrom(string &s)
    {
        int l = 0;
        int r = s.size() - 1;
        while (l <= r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
