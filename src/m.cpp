#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;

    int result = 1;

    for (size_t i = 1; i < S.size(); i += 2)
    {
        char op = S.at(i);
        if (op == '+')
        {
            result += 1;
        }
        else
        {
            result -= 1;
        }
    }
    cout << result << endl;
}
