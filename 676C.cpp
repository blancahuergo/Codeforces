#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K, stA, stB;
	string s;
	cin >> N >> K;
	cin >> s;
	queue<int> changeToA, changeToB;
	stA = stB = 0;
	int record = 1;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'a') {
			changeToB.push(i);
			if ((int) changeToB.size() > K) {
				record = max(record, i-stA);
				stA = changeToB.front() + 1;
				changeToB.pop();
			} else record = max(record, i - stA + 1);
			record = max(record, i - stB + 1);
		} else {
			changeToA.push(i);
			if ((int) changeToA.size() > K) {
				record = max(record, i-stB);
				stB = changeToA.front() + 1;
				changeToA.pop();
			} else record = max(record, i - stB + 1);
			record = max(record, i - stA + 1);
		}
	}
	cout << record << "\n";
	return 0;
}
