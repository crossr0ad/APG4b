#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++)
    {
        cin >> A.at(i) >> B.at(i);
    }

    vector<vector<int>> result(N, vector<int>(N, 0));

    for (size_t i = 0; i < M; i++)
    {
        result.at(A.at(i) - 1).at(B.at(i) - 1) = 1;
        result.at(B.at(i) - 1).at(A.at(i) - 1) = -1;
    }

    for (auto &&i : result)
    {
        for (size_t j = 0; j < i.size(); j++)
        {
            switch (i.at(j))
            {
            case 1:
                cout << "o";
                break;
            case -1:
                cout << "x";
                break;
            case 0:
            default:
                cout << "-";
                break;
            }
            if (j == i.size() - 1)
            {
                cout << endl;
            }
            else
            {
                cout << " ";
            }
        }
    }
}
