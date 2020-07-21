#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

vector<int> ans, curBuild;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int M[N];
	ll rec, h;
	for (int n = 0; n < N; n++) {
		cin >> M[n];
	}
	rec = 0;
	curBuild.assign(N, 0);
	for (int i = 0; i < N; i++) {
		h = (ll) M[i];
		curBuild[i] = M[i];
		for (int j = i+1; j < N; j++) {
			curBuild[j] = min(M[j], curBuild[j-1]);
			h += curBuild[j];
		}
		for (int j = i-1; j >= 0; j--) {
			curBuild[j] = min(M[j], curBuild[j+1]);
			h += curBuild[j];
		}
		if (h > rec) {
			ans = curBuild;
			rec = h;
		}
	}
	cout << ans[0];
	for (int i = 1; i < N; i++) cout << " " << ans[i];
	cout << "\n";
	return 0;
}
