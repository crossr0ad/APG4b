#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 5; // xのスコープはこの行からmain関数のブロックの終わりまで

    if (x == 5)
    {
        int y = 10; // yのスコープはこの行からif文のブロックの終わりまで
        cout << x + y << endl;
    }

    cout << x << endl;
    cout << y << endl;
}
