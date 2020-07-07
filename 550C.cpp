#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string num, cur, ans;
	bool pos = false;
	cin >> num;
	for (int i = 0; i < (int) num.length(); i++) {
		cur = num[i];
		if (cur[0] == '0' || cur[0] == '8') {
			pos = true;
			ans = cur;
			break;
		}
		cur += "0";
		for (int j = i+1; j < (int) num.length(); j++) {
			cur = cur.substr(0, 2);
			cur[1] = num[j];
			if (stoi(cur) % 8 == 0) {
				pos = true;
				ans = cur;
				break;
			}
			cur += "0";
			for (int k = j+1; k < (int) num.length(); k++) {
				cur[2] = num[k];
				if (stoi(cur) % 8 == 0) {
					pos = true;
					ans = cur;
					break;
				}
			}
			if (pos) break;
		}
		if (pos) break;
	}
	if (pos) cout << "YES\n" << ans << "\n";
	else cout << "NO\n";
	return 0;
}
