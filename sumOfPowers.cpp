#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vector<int> a1;
    vector<int> a2;

    for(auto i = 0; i < n; i++) {
        int num;
        cin >> num;
        a1.push_back(num);
    }
    for(auto i = 0; i < n; i++) {
        int num;
        cin >> num;
        a2.push_back(num);
    }

    sort(a1.begin(), a1.end(), greater<int>());
    sort(a2.begin(), a2.end(), greater<int>());

    int64_t maxSum = 0;

    for(auto i = 0; i < n; i++) {
        maxSum += pow(a1[i], a2[i]);
    }

    cout << maxSum % 1000000007;

    return 0;
}

