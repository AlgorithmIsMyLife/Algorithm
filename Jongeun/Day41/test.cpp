#include <iostream>
#include <tuple>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    pair p2{2, 3};
    cout << p2.first << '\n';

    tuple p3{3, 4, 5};
    cout << get<0>(p3) << '\n';
    tuple p4{1, 5, 6};
    tuple p5{2, 3, 4};

    vector<tuple<int, int, int>> temp;

    temp.push_back(p3);
    temp.push_back(p4);
    temp.push_back(p5);

    sort(temp.begin(), temp.end(), [](const auto &t1, const auto &t2)
         { return get<0>(t1) > get<0>(t2); });

    auto t = make_tuple(3, 5);

    for (auto it : temp)
    {
        cout << "first: " << get<0>(it) << '\n';
    }

    // int a = 3;
    // int b = 5;
    // tuple<int &, int &> temp2{a, b}; // tuple 은 이게 되네
}
