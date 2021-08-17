#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> pairs(N);

    for (auto &&pair : pairs)
    {
        cin >> pair.first >> pair.second;
    }

    sort(pairs.begin(), pairs.end(), [](auto a, auto b)
         { return a.second < b.second; });

    for (auto &&pair : pairs)
    {
        cout << pair.first << " " << pair.second << endl;
    }
}
