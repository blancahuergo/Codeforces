#include <iostream>
using namespace std;

int N;
string s;

int main() {
	cin >> N;
	cin >> s;
	int tot = 0;
	for (int i = 1; i < N; i++) {
		if (s[i] == s[i-1]) {
			tot++;
			if (s[i] == 'R') {
				if (i < N-1 && s[i+1] == 'G') s[i] = 'B';
				else s[i] = 'G';
			} else if (s[i] == 'B') {
				if (i < N-1 && s[i+1] == 'G') s[i] = 'R';
				else s[i] = 'G';
			} else {
				if (i < N-1 && s[i+1] == 'R') s[i] = 'B';
				else s[i] = 'R';
			}
		}
	}
	cout << tot << "\n" << s << "\n";
	return 0;
}
