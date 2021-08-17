#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> data(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> data.at(i);
    }

    // dataの中で隣り合う等しい要素が存在するなら"YES"を出力し、そうでなければ"NO"を出力する
    for (size_t i = 0; i < data.size(); i++)
    {
        if (i > 0 && data.at(i - 1) == data.at(i))
        {
            cout << "YES" << endl;
            return 0;
        }
        if (i < 4 && data.at(i) == data.at(i + 1))
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
