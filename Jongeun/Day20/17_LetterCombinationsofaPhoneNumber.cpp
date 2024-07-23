class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {

        // construct the map
        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        vector<string> res;
        if (digits == "")
        {
            return res;
        }

        _letterCombinations(res, digits, m, "", 0);
        return res;
    }

    void _letterCombinations(vector<string> &res, string &digits, unordered_map<char, string> &m, string comb, int start)
    {
        if (start == digits.size())
        {
            res.push_back(comb);
            return;
        }

        for (auto c : m[digits[start]])
        {

            _letterCombinations(res, digits, m, comb + c, start + 1);
        }
    }
};
