#include <cmath>
#include <iostream>

using namespace std;

int getNoOfDigits(int n) {
    int digits = 0;

    while (n > 0) {
        n /= 10;
        digits++;
    }

    return digits;
}

bool isPrime(int n) {
    for(int i = 2; i <= (n / 2); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isCircularPrime(int n) {
    int no_digits = getNoOfDigits(n);

    for(int i = 0; i < no_digits; i++) {
        int last = n % 10;
        int last_removed = n / 10;
        int rotated_n = last_removed + ((int)pow(10, no_digits - 1) * last);

        if (!isPrime(rotated_n))
            return false;

        n = rotated_n;
    }

    return true;
}

int main() {
    cout << "Enter number : ";

    int n;
    cin >> n;

    cout << "Number is " << (isCircularPrime(n) ? "a" : "not a") << " circular prime.";
}