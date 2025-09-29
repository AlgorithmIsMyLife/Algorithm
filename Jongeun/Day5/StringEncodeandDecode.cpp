// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// class Solution
// {
// public:
//     string encode(vector<string> &strs)
//     {
//         string res = "";

//         for (auto i : strs)
//         {
//             int size = i.size();
//             res += (std::to_string(size) + i);
//         }
//         return res;
//     }

//     vector<string> decode(string s)
//     {
//         vector<string> res;
//         int i = 0;
//         while (i < s.size())
//         {
//             int size = s[i] - '0';
//             std::string str2 = s.substr(i + 1, size);
//             res.push_back(str2);
//             i += (size + 1);
//         }

//         return res;
//     }
// };

// int main()
// {
//     Solution obj;
//     vector<string> strs = {"we", "say", ":", "yes", "!@#$%^&*()"};
//     string encoded = obj.encode(strs);
//     cout << "Encoded: " << encoded << endl;

//     vector<string> decoded = obj.decode(encoded);
//     cout << "Decoded: ";
//     for (auto i : decoded)
//     {
//         cout << i << " ";
//     }
//     cout << endl;

//     return 0;
// }
