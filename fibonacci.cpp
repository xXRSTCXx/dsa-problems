#include <bits/stdc++.h>

using namespace std;

void printFibonacci(uint64_t n) {
    uint64_t first = 1;
    uint64_t second = 1;
    uint64_t third = 1;

    cout << third << " ";
    
    while (--n > 0) {
        cout << third << " ";
        first = second;
        second = third;
        third = first + second;
    }
}

int main(int argc, char const* argv[])
{
    uint64_t n;
    cin >> n;

    printFibonacci(n);

    return 0;
}
