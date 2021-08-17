#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    int A;
    cin >> N >> A;

    for (size_t i = 0; i < N; i++)
    {
        string op;
        int B;
        cin >> op >> B;

        if (op == "+")
        {
            A += B;
        }
        else if (op == "-")
        {
            A -= B;
        }
        else if (op == "*")
        {
            A *= B;
        }
        else if (op == "/")
        {
            if (B == 0)
            {
                cout << "error" << endl;
                return 0;
            }
            A /= B;
        }
        else
        {
            cout << "error" << endl;
            return 0;
        }
        cout << i + 1 << ":" << A << endl;
    }
}
