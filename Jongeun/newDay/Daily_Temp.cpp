#include <iostream>

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<int> st;
    st.push(0);
    vector<int> res(temperatures.size());

    for (int i = 1; i < temperatures.size(); i++) {

      while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        res[st.top()] = i - st.top();
        st.pop();
      }
      st.push(i);
    }

    while (!st.empty()) {
      res[st.top()] = 0;
      st.pop();
    }

    return res;
  }
};

int main() {}
