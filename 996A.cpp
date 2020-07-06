#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, bills;
	cin >> N;
	bills = 0;
	bills += N/100;
	N %= 100;
	bills += N/20;
	N %= 20;
	bills += N/10;
	N %= 10;
	bills += N/5;
	N %= 5;
	bills += N;
	cout << bills << "\n";
	return 0;
}
