#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    map<int, int> counter;
    for (size_t i = 0; i < N; i++)
    {
        int j;
        cin >> j;
        counter[j]++;
    }

    int max_value = 0;
    int max_key = -1;
    for (auto &&i : counter)
    {
        if (max_value < i.second)
        {
            max_key = i.first;
            max_value = i.second;
        }
    }
    cout << max_key << " " << max_value << endl;
}
