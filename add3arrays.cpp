#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t n;
    cin >> n;

    int64_t a1[n];
    int64_t a2[n];
    int64_t a3[n];

    for(auto i = 0; i < n; i++) {
        cin >> a1[i];
    }
    for(auto i = 0; i < n; i++) {
        cin >> a2[i];
    }
    for(auto i = 0; i < n; i++) {
        cin >> a3[i];
    }

    int64_t res[n];

    for(auto i = 0; i < n; i++) {
        res[i] = a1[i] + a2[i] + a3[i];
    }
    for(auto i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
}