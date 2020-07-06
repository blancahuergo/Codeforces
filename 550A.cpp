#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	vector<int> posAB, posBA;
	for (int i = 1; i < (int) s.length(); i++) {
		if (s[i-1] == 'A' && s[i] == 'B') {
			posAB.push_back(i);
		} else if (s[i-1] == 'B' && s[i] == 'A') {
			posBA.push_back(i);
		}
	}
	if (posAB.size() >= 2 && posBA.size() >= 2) {
		cout << "YES\n";
	} else if (posAB.size() == 0 || posBA.size() == 0) {
		cout << "NO\n";
	} else {
		bool ans = false;
		for (int i = 0; i < posAB.size(); i++) {
			for (int j = 0; j < posBA.size(); j++)
				if (abs(posAB[i] - posBA[j]) >= 2) {
					ans = true;
					break;
				}
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
