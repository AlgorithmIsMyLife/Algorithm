#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> um;

    for (int i = 0; i < t.size(); i++) {
      um[t[i]]--;
    }

    string ret = s;
    bool checkFailed = true;
    int l = 0, r = 0;
    um[s[r]]++;

    while (r < s.size() && l <= r) {

      if (check(t, um)) {
        checkFailed = false;
        ret = (ret.size() > (r - l + 1)) ? s.substr(l, r - l + 1) : ret;

        um[s[l]]--;
        l++;

      } else {
        r++;
        um[s[r]]++;
      }
    }

    if (checkFailed) {
      return "";
    }
    return ret;
  }

  bool check(string &t, unordered_map<char, int> &um) {

    for (int i = 0; i < t.size(); i++) {
      if (um[t[i]] < 0) {
        return false;
      }
    }

    return true;
  }
};

int main() { Solutin s{}; }
