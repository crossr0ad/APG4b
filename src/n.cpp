#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> scores(N);

    for (size_t i = 0; i < scores.size(); i++)
    {
        cin >> scores.at(i);
    }

    int average = accumulate(scores.begin(), scores.end(), 0) / scores.size();

    for (size_t i = 0; i < scores.size(); i++)
    {
        cout << abs(scores.at(i) - average) << endl;
    }
}
