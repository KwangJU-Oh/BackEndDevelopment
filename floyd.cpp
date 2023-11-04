#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, a, b, c;

	cin >> n >> m;
	cin.get();

	vector<vector<int>>vec(n);
	for (int i = 0; i < n; i++) {
		vec[i].resize(n, 99999999);
		vec[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		cin.get();
		vec[a - 1][b - 1] = min(c, vec[a - 1][b - 1]);
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vec[i][j] > vec[i][k] + vec[k][j]) {
					vec[i][j] = vec[i][k] + vec[k][j];
				}
			}
		}
	}

	for (vector<int>v : vec) {
		for (int elem : v) {
			if (elem == 99999999) {
				cout << 0 << " ";
			}
			else {
				cout << elem << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}