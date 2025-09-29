#include <bits/stdc++.h>
using namespace std;

// use the parameteric search

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int M;
    cin >> M;

    vector<int> trees;
    int tree;

    for (int i = 0; i < N; i++)
    {
        cin >> tree;
        trees.push_back(tree);
    }

    sort(trees.begin(), trees.end());

    int idx = trees.size() - 1;
    int height = trees[idx];

    int sum = 0;
    int k = 0; // the number of tree that can be cutted

    while (sum < M)
    {

        while (idx > -1 && height < trees[idx])
        {
            idx--;
            k++;
        }

        sum += k;

        height--;
    }

    cout << height + 1 << '\n';

    return 0;
}
