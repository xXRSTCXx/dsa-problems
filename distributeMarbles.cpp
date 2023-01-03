#include <bits/stdc++.h>

using namespace std;

int distributeMarbles(int N, int c1, int n1, int c2, int n2) {
    //todo handle edge cases

    int minCost = INT_MAX;

    for (auto i = 0; i <= N; i += 1) {
        int remainingMarbles = N - i;

        if (i % n1 == 0 && remainingMarbles % n2 == 0) {
            int cost = c1 * (i / n1) + c2 * (remainingMarbles / n2);

            if (cost < minCost) {
                minCost = cost;
            }
        }
    }
    
    if (minCost == INT_MAX)
        minCost = -1;

    return minCost;
}

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;

    int c1, n1, c2, n2;
    cin >> c1 >> n1 >> c2 >> n2;

    int minCost = distributeMarbles(n, c1, n1, c2, n2);

    // cout << "\n" << "Min cost : " << minCost;
    if (minCost == -1)
        cout << "Impossible";
    else
        cout << minCost;
}