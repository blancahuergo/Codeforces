#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s, cur = "";
	vector<string> ans;
	cin >> s;
	int i = 0;
	bool pos = true;
	while(i < (int) s.length()) {
		if (s[i] == '.') {
			if (cur.length() == 0 || i == (int) s.length() - 1 || s[i+1] == '.') {
				pos = false;
				break;
			}
			if (cur.length() <= 10) {
				if (cur.length() <= 8) ans.emplace_back(cur + "." + s.substr(i+1, 1));
				else if (!ans.size()) {
					pos = false;
					break;
				}
				else if (cur.length() == 9) {
					ans[ans.size() - 1] += cur.substr(0, 1);
					ans.emplace_back(cur.substr(1, 8) + "." + s.substr(i+1, 1));
				} else {
					ans[ans.size() - 1] += cur.substr(0, 2);
					ans.emplace_back(cur.substr(2, 8) + "." + s.substr(i+1, 1));
				}
			} else {
				pos = false;
				break;
			}
			i += 2;
			cur = "";
		} else {
			cur += s.substr(i, 1);
			i++;
		}
	}
	if (cur.length() > 2 || ans.size() == 0) pos = false;
	else ans[ans.size() - 1] += cur;
	if (pos) {
		cout << "YES\n";
		for (int i = 0; i < (int) ans.size(); i++) cout << ans[i] << "\n";
	} else cout << "NO\n";
	return 0;
}
