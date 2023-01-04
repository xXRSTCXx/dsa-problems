#include <bits/stdc++.h>

using namespace std;

void appendNumerals(string &s, int n, int place_val, char unit, char half, char nextPlace) {
    int multiple = n / place_val;

    if (multiple == 9) {
        s += unit;
        s += nextPlace;
    }
    else if (multiple > 5) {
        multiple = multiple - 5;
        s += half;
        s.append(multiple, unit);
    }
    else if (multiple == 4) {
        s += unit;
        s += half;
    }
    else {
        s.append(multiple, unit);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    string roman;

    int m_of_1000 = n / 1000;
    roman.append(m_of_1000, 'M');

    n %= 1000;
    appendNumerals(roman, n, 100, 'C', 'D', 'M');

    n %= 100;
    appendNumerals(roman, n, 10, 'X', 'L', 'C');

    n %= 10;
    appendNumerals(roman, n, 1, 'I', 'V', 'X');

    cout << roman;

    return 0;
}
