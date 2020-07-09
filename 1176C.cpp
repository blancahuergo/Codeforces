#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> dict;

int main() {
	int N, ans, cur;
	cin >> N;
	int counts[] = {0, 0, 0, 0, 0, 0};
	dict[4] = 0;
	dict[8] = 1;
	dict[15] = 2;
	dict[16] = 3;
	dict[23] = 4;
	dict[42] = 5;
	ans = 0;
	for (int n = 0; n < N; n++) {
		cin >> cur;
		cur = dict[cur];
		if (cur == 0) counts[0]++;
		else if (counts[cur-1] > counts[cur]) counts[cur]++;
		else ans++;
	}
	cur = counts[5];
	for (int i = 0; i < 5; i++) ans += counts[i]-cur;
	cout << ans << "\n";
	return 0;
}
