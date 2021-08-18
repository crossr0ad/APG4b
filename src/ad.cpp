#include <bits/stdc++.h>
using namespace std;

#define MAXLEN_INT 5
#define MAXLEN_VEC 5
// #define DEBUG

map<string, int> intvar;
map<string, vector<int>> vecvar;
// vector<string> op_list = {"+", "-"};
string buff;

int int_exp();
vector<int> vec_exp();

void print_vec(vector<int> vec)
{
    cout << "[ ";
    for (auto &&i : vec)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
}

int main()
{
    int N;
    cin >> N;
    int loop_num = 0;

    while (loop_num++ < N)
    {
        string command;
        cin >> command;

#ifdef DEBUG
        cout << "main: command is " << command << endl;
#endif
        if (command == "int")
        {
            string varname;
            cin >> varname;

            cin >> buff >> buff; // "="を捨てる

            auto value = int_exp();
            intvar[varname] = value;
#ifdef DEBUG
            cout << "int " << value << " was added as " << varname << endl;
#endif
            continue;
        }
        if (command == "print_int")
        {
            cin >> buff;

            cout << int_exp() << endl;
            continue;
        }
        if (command == "vec")
        {
            string varname;
            cin >> varname;

            cin >> buff >> buff; // "="を捨てる
            auto value = vec_exp();
            vecvar[varname] = value;
#ifdef DEBUG
            cout << "vector " << varname << " was added" << endl;
#endif
            // cin >> buff; // ";"を捨てる
            continue;
        }
        if (command == "print_vec")
        {
            cin >> buff;

            print_vec(vec_exp());
            continue;
        }
        cout << "error: invalid command" << endl;
        exit(1);
    }
}

int int_term()
{
    int value;
    try
    {
        value = stoi(buff);
    }
    catch (const invalid_argument &e)
    {
        try
        {
            value = intvar.at(buff);
        }
        catch (const out_of_range &f)
        {
            cerr << "error: var " << buff << " is not found in intvar" << endl;
            exit(1);
        }
    }
#ifdef DEBUG
    cout << "int_term: " << value << endl;
#endif
    return value;
}

int int_exp()
{
    int value = int_term();
    cin >> buff;
    while (buff == "+" || buff == "-")
    {
        if (buff == "+")
        {
            cin >> buff;
            value += int_term();
        }
        else
        {
            cin >> buff;
            value -= int_term();
        }
        cin >> buff;
    }

#ifdef DEBUG
    cout << "int_exp: " << value << endl;
#endif
    return value;
}

vector<int> vec_term()
{
#ifdef DEBUG
    cout << "vec_term: buff is " << buff << endl;
#endif

    // vec変数
    if (buff != "[")
    {
        string varname = buff;
        try
        {
            return vecvar.at(varname);
        }
        catch (const out_of_range &f)
        {
            cerr << "error: var " << varname << " is not found in vecvar" << endl;
            exit(1);
        }
    }

    // vec値
    vector<int> value;
    for (; buff != "]"; cin >> buff)
    {
        cin >> buff;
        value.push_back(int_term());
    }
    return value;
}

vector<int> vec_exp()
{
    auto add = [](auto x, auto y)
    {
        for (size_t i = 0; i < x.size(); i++)
        {
            x.at(i) += y.at(i);
        }

        return x;
    };

    auto subtract = [](auto x, auto y)
    {
        for (size_t i = 0; i < x.size(); i++)
        {
            x.at(i) -= y.at(i);
        }

        return x;
    };

    vector<int> value = vec_term();
    cin >> buff;
    while (buff == "+" || buff == "-")
    {
        if (buff == "+")
        {
            cin >> buff;
            value = add(value, vec_term());
        }
        else
        {
            cin >> buff;
            value = subtract(value, vec_term());
        }
        cin >> buff;
    }
    return value;
}
