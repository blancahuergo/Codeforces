#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, one, two, three, shortest;
	string s;
	cin >> T;
	while(T--) {
		cin >> s;
		one = two = three = -1;
		shortest = s.length() + 1;
		for (int i = 0; i < (int) s.length(); i++) {
			if (s[i] == '1') one = i;
			else if (s[i] == '2') two = i;
			else three = i;
			if (one >= 0 && two >= 0 && three >= 0)
				shortest = min(shortest, max(one, max(two, three)) - min(one, min(two, three))+1);
		}
		if (shortest <= (int) s.length()) cout << shortest << "\n";
		else cout << "0\n";
	}
	return 0;
}
