#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

map<string, int> intvar;         // int型変数の、変数名と値の連想配列
map<string, vector<int>> vecvar; // vec型変数の、変数名と値の連想配列
string buff;                     // 常に先頭のトークンを格納する

int int_exp();
vector<int> vec_exp();

// vector<int>を引数とし、その要素をホワイトスペース空きで出力する。
// 前後には"[", "]"を出力する。
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
    auto loop_num = 0;

    while (loop_num++ < N)
    {
        string command;
        cin >> command;

#ifdef DEBUG
        cout << "main: command is " << command << endl;
#endif

        // intコマンドを処理する。
        // int_exp()を呼び出し、返り値をint型変数の連想配列に登録する。
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

        // print_intコマンドを処理する。
        // int_exp()を呼び出し、返り値を標準出力に出力する。
        if (command == "print_int")
        {
            cin >> buff;

            cout << int_exp() << endl;
            continue;
        }

        // vecコマンドを処理する。
        // vec_exp()を呼び出し、返り値をvec型変数の連想配列に登録する。
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
            continue;
        }

        // print_vecコマンドを処理する。
        // vec_exp()を呼び出し、返り値を標準出力に出力する。
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

// int項を処理する。
// 数字かint型変数の参照かは、簡単にstoi()が失敗する（=トークンが数字列でない）かどうかで判定する。
// 加えて、（デバッグのため）int型変数の連想配列に無い変数が参照された場合、エラーを表示し終了する。
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

// int式を処理する。
int int_exp()
{
    auto value = int_term();
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

// vec項を処理する。
// vec変数かvec値かは、先頭が"["かどうかで判定する。
vector<int> vec_term()
{
#ifdef DEBUG
    cout << "vec_term: buff is " << buff << endl;
#endif

    // vec変数を処理する。
    // vec型変数の仮想配列を参照し、得られたvectorを返す。
    // （デバッグのため）連想配列に無い変数が参照された場合、エラーを表示し終了する。
    if (buff != "[")
    {
        auto varname = buff;
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

    // vec値を処理する。
    // 返り値用のvectorを宣言し、そこにint項の返り値をpush_back()で順次格納する。
    vector<int> value;
    for (; buff != "]"; cin >> buff)
    {
        cin >> buff;
        value.push_back(int_term());
    }
    return value;
}

// vec式を処理する。
// vectorの要素ごとの加算・減算のために、事前にlambda式を定義する。
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

    // vec値を処理する。
    auto value = vec_term();
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
