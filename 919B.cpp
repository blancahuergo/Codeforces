#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums;
vector<string> orig;

void fillOrig(string curStr, int curSum) {
	if (curSum == 10) {
		reverse(curStr.begin(), curStr.end());
		orig.push_back(curStr);
		return;
	} else if (curSum > 10) return;
	for(char c = curStr[curStr.length()-1]; c > '0'; c--) fillOrig(curStr + c, curSum + (c-'0'));
}

void fillIn(int L) {
	string cur;
	for (int i = 0; i < (int) orig.size(); i++) {
		cur = orig[i];
		if ((int) cur.length() > L) continue;
		while((int) cur.length() < L) cur = "0" + cur;
		do {
			if (cur[0] != '0') nums.push_back(stoi(cur));
		} while(next_permutation(cur.begin(), cur.end()));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	for (int c = 1; c <= 9; c++) fillOrig(to_string(c), c);
	fillIn(2);
	int i = 3;
	while((int) nums.size() < k) {
		fillIn(i);
		i++;
	}
	sort(nums.begin(), nums.end());
	cout << nums[k-1] << "\n";
	return 0;
}
