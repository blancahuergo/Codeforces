#include <iostream>
using namespace std;
typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	int X[N];
	ll tot[N];
	for (int n = 0; n < N; n++) cin >> X[n];
	tot[N-1] = (ll) X[N-1];
	for (int i = N-2; i >= N-K; i--) tot[i] = tot[i+1]+X[i];
	for (int i = N-K-1; i >= 0; i--) tot[i] = tot[i+1]-X[i+K]+X[i];
	ll rec = tot[N-K] + tot[N-2*K];
	int recA = N-2*K, curB= N-K, recB = N-K;
	for (int i = N-2*K - 1; i >= 0; i--) {
		if (tot[i+K] >= tot[curB]) curB = i+K;
		if (tot[i]+tot[curB] >= rec) {
			rec = tot[i]+tot[curB];
			recA = i;
			recB = curB;
		}
	}
	cout << recA+1 << " " << recB+1 << "\n";
	return 0;
}
