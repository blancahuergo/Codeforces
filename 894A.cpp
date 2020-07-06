#include <iostream>
using namespace std;

int main() {
	string s;
	long long int tot = 0;
	cin >> s;
	long long int totQ[(int) s.length()];
	if (s[0] == 'Q') totQ[0] = 1;
	else totQ[0] = 0;
	for (int i = 1; i < (int) s.size(); i++) {
		if (s[i] == 'Q') {
			totQ[i] = totQ[i-1]+1;
		} else totQ[i] = totQ[i-1];
	}
	long long int QA = 0;
	for (int i = 0; i < (int) s.size(); i++) {
		if (s[i] == 'A') {
			QA += totQ[i];
		} else if (s[i] == 'Q') {
			tot += QA;
		}
	}
	cout << tot << "\n";
	return 0;
}
