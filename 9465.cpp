#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, n, a;

	cin >> T;
	cin.get();

	for (int t = 0; t < T; t++) {
		vector<vector<long long int>>dp(2, vector<long long int>(100002, 0));
		cin >> n;
		cin.get();

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a;
				cin.get();

				dp[i][j + 2] = a;
			}
		}

		for (int i = 2; i < n + 2; i++) {
			dp[0][i] = dp[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = dp[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}

		sort(dp[0].begin(), dp[0].end());
		sort(dp[1].begin(), dp[1].end());
		cout << max(dp[0][dp[0].size() - 1], dp[1][dp[1].size() - 1]) << "\n";
	}

	return 0;
}