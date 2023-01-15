#include <bits/stdc++.h>

using namespace std;

int getEqualSumSubsets(int n) {
    int binary_repr = pow(2, n);

    int subsets = 0;

    // O (n * 2 ^ n) 💀
    // going through all subsets
    for (int i = 1; i < binary_repr; i++) {
        int subsetSum = 0;
        int remainderSum = 0;

        for (int j = 0; j < n; j++) {
            // if there is a 1 at nth position from right
            // ie if j + 1 is in the current subset
            if ((i & (1 << j))) {
                subsetSum += j + 1;
            }
            else {
                remainderSum += j + 1;
            }
        }

        // if they have equal sum
        if (subsetSum == remainderSum)
            subsets++;
    }

    // we actually include the same pair twice in opposite orders
    // so divide by 2 to ignore duplicates
    return subsets / 2;
}

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;

    cout << getEqualSumSubsets(n);

    return 0;
}