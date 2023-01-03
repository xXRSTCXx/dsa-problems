#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	if (s1.size() != s2.size()) {
		int diff = s1.size() - s2.size();
		string pad = "";
		for (int i = 0; i < abs(diff); i++) {
			pad += "0";
		}
		if (diff < 0) {
			s1 = pad + s1;
		}
		else {
			s2 = pad + s2;
		}
	}

	int carry = 0;

	string result = "";

	for (int i = s2.size() - 1; i >= 0; i--) {
		int n1 = s1.at(i) - '0';
		int n2 = s2.at(i) - '0';

		int res = n1 + n2 + carry;

		carry = 0;
		if (res > 1) {
			res = res == 2 ? 0 : 1;
			carry = 1;
		}

		char res_ascii = res + '0';

		result = res_ascii + result;
		// cout << result  << "\t";
	}

	if (carry) {
		char carry_ascii = (carry + '0');
		result = carry_ascii + result;
	}

	cout << "Answer : " << result;
}