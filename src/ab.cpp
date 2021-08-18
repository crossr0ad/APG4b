#include <bits/stdc++.h>
using namespace std;

// 以下に、24時間表記の時計構造体 Clock を定義する

// Clock構造体のメンバ変数を書く
//   int hour    時間を表す (0~23の値をとる)
//   int minute  分を表す   (0~59の値をとる)
//   int second  秒を表す   (0~59の値をとる)

struct Clock
{
    int hour;
    int minute;
    int second;

    void set(int h, int m, int s)
    {
        // 時・分・秒を表す3つの引数を受け取り、
        // それぞれ、メンバ変数 hour, minute, second に代入する
        hour = h;
        minute = m;
        second = s;
    }
    string to_str()
    {
        // メンバ変数が表す時刻の文字列を返す
        // 時刻の文字列は次のフォーマット
        // "HH:MM:SS"
        // HH、MM、SSはそれぞれ時間、分、秒を2桁で表した文字列
        string s;

        if (hour < 10)
        {
            s += "0";
        }
        s += to_string(hour) + ":";

        if (minute < 10)
        {
            s += "0";
        }
        s += to_string(minute) + ":";

        if (second < 10)
        {
            s += "0";
        }
        s += to_string(second);

        return s;
    }
    void shift(int diff_second)
    {
        // diff_second 秒だけメンバ変数が表す時刻を変更する(ただし、日付やうるう秒は考えない)
        // diff_second の値が負の場合、時刻を戻す
        // diff_second の値が正の場合、時刻を進める
        // diff_second の値は -86400 ~ 86400 の範囲を取とりうる
        second += diff_second;
        while (second >= 60)
        {
            second -= 60;
            minute++;
        }
        while (second < 0)
        {
            second += 60;
            minute--;
        }

        while (minute >= 60)
        {
            minute -= 60;
            hour++;
        }
        while (minute < 0)
        {
            minute += 60;
            hour--;
        }

        while (hour >= 24)
        {
            hour -= 24;
        }
        while (hour < 0)
        {
            hour += 24;
        }
    }
};

// -------------------
// ここから先は変更しない
// -------------------

int main()
{
    // 入力を受け取る
    int hour, minute, second;
    cin >> hour >> minute >> second;
    int diff_second;
    cin >> diff_second;

    // Clock構造体のオブジェクトを宣言
    Clock clock;

    // set関数を呼び出して時刻を設定する
    clock.set(hour, minute, second);

    // 時刻を出力
    cout << clock.to_str() << endl;

    // 時計を進める(戻す)
    clock.shift(diff_second);

    // 変更後の時刻を出力
    cout << clock.to_str() << endl;
}
