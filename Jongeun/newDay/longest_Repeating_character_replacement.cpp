#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {

    vector<int> v(26, 0);
    int l = 0, r = 0;
    int maxLength{0};
    v[s[r] - 'A']++;

    while (r < s.size()) {
      if (check(k, v)) {
        maxLength = max(maxLength, r - l + 1);
        r++;
        v[s[r] - 'A']++;
      } else {
        v[s[l] - 'A']--;
        l++;
      }
    }

    return maxLength;
  }

  bool check(int k, vector<int> v) {
    int total{0};
    int maxVal{0};
    for (int i = 0; i < 26; i++) {
      total += v[i];
      maxVal = max(maxVal, v[i]);
    }

    if (total - maxVal <= k)
      return true;
    else
      return false;
  }
};

int main() { Solutin s{}; }
