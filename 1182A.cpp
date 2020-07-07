#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

int main() {
	vector<ll> DP = vector<ll>(61, 0ll);
	DP[0] = 1;
	for (int i = 2; i <= 60; i+=2) DP[i] = 2*DP[i-2];
	int N;
	cin >> N;
	cout << DP[N];
	return 0;
}
