#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, a;
	int idx = 0;

	cin >> n;
	cin.get();

	vector<int>v;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			cin >> a;
			cin.get();
			v.push_back(a);
		}
	}

	vector<int>dp(v.size(), -1);
	dp[0] = v[0];

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			idx = idx + 1;
			if (j == 0) {
				dp[idx] = dp[idx - i + 1] + v[idx];
			}
			else if (j == i - 1) {
				dp[idx] = dp[idx - i] + v[idx];
			}
			else {
				dp[idx] = max(dp[idx - i], dp[idx - i + 1]) + v[idx];
			}
		}
	}

	sort(dp.begin(), dp.end());
	cout << dp[dp.size() - 1];

	return 0;
}