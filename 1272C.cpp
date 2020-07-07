#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	bool broken[] = {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};
	string s;
	cin >> N >> K;
	cin >> s;
	char c;
	while(K--) {
		cin >> c;
		broken[c - 'a'] = false;
	}
	long long int count, total;
	count = total = 0ll;
	for (int i = 0; i < (int) s.length(); i++) {
		if (broken[s[i] - 'a'] == false) count++;
		else {
			total += count*(count+1)/2;
			count = 0;
		}
	}
	total += count*(count+1)/2;
	cout << total << "\n";
	return 0;
}
