#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1000000000
vector<long long int>sec(500001, INF);

int main() {
	int n, k;

	cin >> n >> k;
	cin.get();

	priority_queue<pair<long long int, int>>p;
	p.push(make_pair(0, n));
	sec[n] = 0;

	while (!p.empty()) {
		int cur = p.top().second;
		long long int cursec = -p.top().first;
		p.pop();

		if (cursec > sec[cur]) {
			continue;
		}

		if (cur - 1 >= 0 && cur - 1 <= 100000 && sec[cur - 1] > cursec + 1) {
			sec[cur - 1] = cursec + 1;
			p.push(make_pair(-sec[cur - 1], cur - 1));
		}
		if (sec[cur + 1] > cursec + 1 && cur + 1 >= 0 && cur + 1 <= 100000) {
			sec[cur + 1] = cursec + 1;
			p.push(make_pair(-sec[cur + 1], cur + 1));
		}
		if (sec[cur * 2] > cursec && cur * 2 >= 0 && cur * 2 <= 100000) {
			sec[cur * 2] = cursec;
			p.push(make_pair(-sec[cur * 2], cur * 2));
		}

	}

	cout << sec[k];

	return 0;
}