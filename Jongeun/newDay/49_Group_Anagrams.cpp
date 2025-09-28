
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {

    map<string, vector<string>> words;

    for (int i = 0; i < strs.size(); i++) {
      string SortedS = strs[i];
      sort(SortedS.begin(), SortedS.end());

      words[SortedS].emplace_back(strs[i]);
    }

    vector<vector<string>> result{};
    for (const auto &i : words) {
      result.emplace_back(i.second);
    }
    return result;
  }
};
