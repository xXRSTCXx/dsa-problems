/**
 * A 'weird' number is a number that has repeated prime factors.
 * Write a function isWeirdNumber(int n) that takes an integer n and returns a boolean indicating
 * if it is a weird number.	
*/

#include <iostream>
#include <vector>

using namespace std;
bool isWeirdNumber(int n) {
	// first have to find prime factors	
	int temp = n;
	int factor = 2;

	vector<int> factors;
	
	bool isWeird = false;

	while(temp >= 2) {
		if (temp % factor == 0) {
			if (factors.size() && factors.back() == factor) {
				//repeated factor
				isWeird = true;
			} 
			factors.push_back(factor);
			temp /= factor;
		} else {
			factor++;
		}
	}
	
	cout << "Prime factors : \n";
	for(auto factor: factors) {
		cout << factor << "\n";
	}
	return isWeird;
}

int main() {
	int n;

	cout << "Enter number : "; 

	cin >> n;

	cout << "\n";
	
	bool isWeird = isWeirdNumber(n);

	cout << "\nThe number is " << (isWeird ? "weird" : "not weird") << " because it " 
		<< (isWeird ? "has " : "doesn't have ") << "repeated factors.\n";
}
