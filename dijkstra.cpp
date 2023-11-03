
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>>vec(20001);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int V, E, u, v, w, K;
	int inf = 3000000;

	cin >> V >> E;
	cin.get();
	cin >> K;
	cin.get();

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		cin.get();
		vec[u - 1].push_back(make_pair(v-1,w));
	}

	vector<int>distance(20001, inf);
	priority_queue<pair<int, int>>que;
	que.push(make_pair(0,K-1));

	while (!que.empty()) {
		int cur = que.top().second;
		int dist = -que.top().first;
		que.pop();

		if (dist > distance[cur]) {
			continue;
		}
		else {
			for (int i = 0; i < vec[cur].size(); i++) {
				if (dist + vec[cur][i].second < distance[vec[cur][i].first]) {
					distance[vec[cur][i].first] = dist + vec[cur][i].second;
					que.push(make_pair(-distance[vec[cur][i].first], vec[cur][i].first));
				}
			}
		}
	}

	for (int i = 0; i < V; i++) {
		if (i == K - 1) {
			cout << 0 << "\n";
		}
		else if (distance[i] == inf) {
			cout << "INF" << "\n";
		}
		else {
			cout << distance[i] << "\n";
		}
	}

	return 0;
}
