#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string encode(vector<string> &strs) {
    string encoded = "";

    for (int i = 0; i < strs.size(); i++) {
      encoded += (to_string(strs[i].size()) + "#");
      encoded += strs[i];
    }

    return encoded;
  }

  vector<string> decode(string s) {

    vector<string> decoded{};

    int i = 0;

    while (i < s.size()) {
      string num = "";

      while (s[i] != '#') {
        num += s[i];
        i++;
      }

      int number = stoi(num);
      i++;

      string input = "";

      for (int j = 0; j < number; j++) {
        input += s[i];
        i++;
      }

      decoded.push_back(input);
    }

    return decoded;
  }
};

int main() { Solutin s{}; }
