#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int dp[1005][3];

int main() {
	int n, a;

	cin >> n;
	cin.get();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a;
			cin.get();
			dp[i][j] = a;
		}
	}

	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = dp[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = dp[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}

	cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));

	return 0;
}