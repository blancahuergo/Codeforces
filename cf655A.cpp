#include <iostream>
using namespace std;

int main() {
	int T, N;
	cin >> T;
	while(T--) {
		cin >> N;
		cout << "1";
		for (int i = 1; i < N; i++) cout << " 1";
		cout << "\n";
	}
	return 0;
}
