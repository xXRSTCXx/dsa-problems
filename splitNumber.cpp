#include <bits/stdc++.h>
#include <cmath>

using namespace std;

uint32_t countDigits(uint64_t n) {
    uint32_t digits = 0;

    while (n > 0) {
        digits++;
        n = n / 10;
    }

    return digits;
}

int main(int argc, char const *argv[])
{
    // input 
    uint32_t l;
    uint64_t n;
    cin >> l;
    cin >> n;

    // split number
    uint32_t mid = l / 2; 
    uint64_t divisor = (uint64_t)pow(10, l - mid);
    uint64_t first = n / divisor; 
    uint64_t second = n % divisor;
    uint64_t sum = first + second;

    uint32_t digitDiff = (l - mid) - countDigits(second);
    if (digitDiff != 0) { 
        // if it has leading zeroes
        mid = mid + digitDiff; 
        first = n / (uint64_t)pow(10, l - mid);
        second = n % (uint64_t) pow(10, l - mid);

        sum = first + second;
    }

    if (l & 1 == 1 && digitDiff == 0) {
        // don't have to do this if we shifted mid before
        // (numbers with more digits are always bigger)

        // also do this only if its an odd number of digits 
        // for an even number of digits, the number can be split equally

        mid = l / 2 + 1;
        second = n % (uint64_t) pow(10, l - mid);
        first = n / (uint64_t)pow(10, l - mid);

        if ((first + second) < sum) {
            sum = first + second;
        }
    }

    cout << sum;

    return 0;
}
