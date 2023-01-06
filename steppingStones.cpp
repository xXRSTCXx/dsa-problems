#include <bits/stdc++.h>

using namespace std;

int computeSteps(int x, int y) {
    int sum = x + y;
    int median;
    
    median = ceil((double)sum / 2);
    

    int increment = 1;
    int steps = 0;
    while (x < median) {
        if (x + increment >= y && x != 1) {
            increment = y - 1 - x;
        }
        x += increment;
        increment++;
        steps++;
    }
    median = x;

    int decrement = 1;
    while (y > median) {
        if (y - decrement < median && decrement != 1) {
            decrement = y - median;
        }
        y -= decrement;
        decrement++;
        steps++;
    }

    return steps;
}

int main(int argc, char const* argv[])
{
    int x, y;
    cin >> x >> y;

    cout << computeSteps(x, y);

    return 0;
}
