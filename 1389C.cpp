#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <climits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

string s;
vvi pos;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, maxL, k, l, cur;
	cin >> T;
	while(T--) {
		cin >> s;
		pos.assign(10, vi());
		for (int i = 0; i < (int) s.length(); i++) {
			pos[s[i] - '0'].emplace_back(i);
		}
		maxL = 2;
		for (int a = 0; a <= 9; a++) {
			if (pos[a].size() == 0) continue;
			for (int b = 0; b <= 9; b++) {
				if (pos[b].size() == 0) continue;
				cur = 0;
				k = 0;
				l = 0;
				if (a != b) {
					while((k < (int) pos[a].size()) && (l < (int) pos[b].size())) {
						if (pos[a][k] < pos[b][l]) {
							cur += 2;
							while((k < (int) pos[a].size()) && (pos[a][k] < pos[b][l])) k++;
							l++;
						} else l++;
					}
				} else cur = pos[a].size();
				maxL = max(maxL, cur);
			}
		}
		cout << (s.length() - maxL) << "\n";
	}
	return 0;
}
