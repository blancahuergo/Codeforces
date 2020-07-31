#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, counts, k;
	string s, goal = "abacaba", extra = "caba", beg = "abac";
	cin >> T;
	int pos, lastP;
	while(T--) {
		cin >> N;
		cin >> s;
		counts = 0;
		lastP = pos = -1;
		for (int i = 0; i <= N-7; i++) {
			pos = i;
			for (int j = 0; j < 7; j++) {
				if (s[i+j] != goal[j]) {
					pos = -1;
					break;
				}
			}
			if (pos == i) {
				counts++;
				lastP = pos;
			}
		}
		if (counts > 1) cout << "NO\n";
		else {
			if (counts == 1) {
				pos = lastP;
				cout << "YES\n";
				for (int i = 0; i < pos; i++) {
					if (s[i] == '?') cout << 'd';
					else cout << s[i];
				}
				cout << "abacaba";
				for (int i = pos+7; i < N; i++) {
					if (s[i] == '?') cout << 'd';
					else cout << s[i];
				}
				cout << "\n";
			} else {
				pos = -1;
				for (int i = 0; i <= N-7; i++) {
					pos = i;
					for (int j = 0; j < 7; j++) {
						if (s[i+j] != goal[j] && s[i+j] != '?') {
							pos = -1;
							break;
						}
					}
					if (pos == i) {
						k = 0;
						pos = i;
						if (i+10 < N) {
							for (int j = i+7; j <= i+10; j++) {
								pos = -1;
								if (s[j] != extra[k]) {
									pos = i;
									break;
								}
								k++;
							}
						}
						if (pos == i) {
							pos = i;
							if (i >= 4) {
								k = 3;
								for (int j = i-1; j >= i-4; j--) {
									pos = -1;
									if (s[j] != beg[k]) {
										pos = i;
										break;
									}
									k--;
								}
							}
							if (pos == i) break;
						}
					}
				}
				if (pos == -1) cout << "NO\n";
				else {
					cout << "YES\n";
					for (int i = 0; i < pos; i++) {
						if (s[i] == '?') cout << 'd';
						else cout << s[i];
					}
					cout << "abacaba";
					for (int i = pos + 7; i < N; i++) {
						if (s[i] == '?') cout << 'd';
						else cout << s[i];
					}
					cout << "\n";
				}
			}
		}
	}
	return 0;
}
