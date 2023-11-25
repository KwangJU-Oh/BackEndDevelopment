#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, a, x, y, z;

	cin >> n;
	cin.get();

	vector<int>v(n + 1);
	vector<int>dp(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> a;
		cin.get();

		v[i] = a;
	}

	dp[0] = 0;
	dp[1] = v[1];
	dp[2] = v[1] + v[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + v[i - 1] + v[i], max(dp[i - 2] + v[i], dp[i - 1]));
	}

	cout << dp[n];

	return 0;
}