#include <bits/stdc++.h>

using namespace std;

bool isPrime(uint64_t n) {
    for (auto i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

uint64_t sumOfPrimeFactors(uint64_t n) {
    if (n == 1)
        return 0;

    for (auto i = 2; i <= n;i++) {
        if (isPrime(i)) {
            if (n % i == 0) {
                return i + sumOfPrimeFactors(n / i);
            }
        }
    }

    return 0;
}

int main(int argc, char const* argv[])
{
    uint64_t n;
    cin >> n;

    cout << sumOfPrimeFactors(n);

    return 0;
}
