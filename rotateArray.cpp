#include <iostream>
#include <vector>

using std::cout;
using std::endl;

template<class T>
void printVector(std::vector<T> vec) {
    for (auto elem : vec) {
        cout << elem << "  ";
    }
    cout << endl;
}

std::vector<int> rotateArray(std::vector<int> arr, int k) {
    int size = arr.size();
    int elementsToPop = k % size;

    std::vector<int> newVector;

    for (int i = size - k; i < size; i++) {
        newVector.push_back(arr[i]);
    }

    for (int i = 0; i <= size - 1 - k; i++) {
        newVector.push_back(arr[i]);
    }

    return newVector;
}

int main(int argc, char const* argv[])
{
    std::vector<int> ar = { 1, 2, 3, 4, 5, 6, 7 };

    std::vector<int> result = rotateArray(ar, 6);
    printVector(result);

    return 0;
}