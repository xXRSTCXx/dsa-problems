#include <bits/stdc++.h>

using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int computeSteps_optimized_dp(int arr[], int n)
{
    // jumps[n-1] will hold the result
    int* jumps = new int[n];
    int i, j;
 
    if (n == 0 || arr[0] == 0)
        return INT_MAX;
 
    jumps[0] = 0;
 
    // Find the minimum number of jumps to reach arr[i]
    // from arr[0], and assign this value to jumps[i]
    for (i = 1; i < n; i++) {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++) {
            if (i <= j + arr[j] && jumps[j] != INT_MAX) {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n - 1];
}
int computeSteps(int arr[], int size, int i = 0) {
    int steps = INT_MAX;

    for(int s = 1; s <= arr[i]; s++) {
        if (i + s >= size - 1)
            return 1;

        steps = min(steps, computeSteps(arr, size, i + s));
    }

    if (steps == INT_MAX)
        return INT_MAX;

    return steps + 1;
}

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int steps = computeSteps_optimized_dp(arr, n);
    cout << (steps == INT_MAX ? -1 : steps);

    //cout << computeSteps(arr, n);
    
    return 0;
}
