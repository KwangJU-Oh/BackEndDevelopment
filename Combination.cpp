//백트래킹을 하기 위해선 순열과 조합에 대해 알아야 편함(순열, 조합 - 백트래킹)
//순열 - <algorithm> 헤더의 next_permutation(iter::begin(), iter::end())를 사용한다.
// next_permutation -> bool값 return(다음 순열이 있으면 true, 없으면 false)
//nPr 순열 - reverse(iter::begin() + r, iter::end()) 후 next_permutation사용
//nCr 조합 - 또 다른 배열에서 true를 r개로 세팅 ex) a = [true,true,false,false] -> 4C2 조합
//이 배열을 prev_permutation -> 이전 순열이 있으면 true, 없으면 false 반환을 이용해 해당
//인덱스에 해당하는 원소 이용
//순열은 오름차순 정렬, 조합은 내림차순 정렬이 되어야 한다!

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>>v(51);
vector<pair<int, int>>house;
vector<pair<int, int>>chicken;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, a, cost;
	
	cin >> N >> M;
	cin.get();

	for (int i = 0; i < N; i++) {
		v[i].resize(N);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a;
			cin.get();

			if (a == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (a == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	vector<int>ans;

	for (int t = 1; t <= M; t++) {

		//조합할 배열의 내림차순 정렬
		vector<int>comb(chicken.size(), false);
		for (int i = 0; i < t; i++) {
			comb[i] = true;
		}

		do {
			int sum = 0;
			vector<int>dist(house.size(), 100000); //각 집의 치킨 거리

			for (int i = 0; i < house.size(); i++) {
				for (int j = 0; j < comb.size(); j++) {
					if (comb[j] == true) {
						cost = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
						if (cost < dist[i]) {
							dist[i] = cost;
						}
					}
				}
			}

			for (int k = 0; k < house.size(); k++) {
				sum = sum + dist[k];
			}
			ans.push_back(sum);

		} while (prev_permutation(comb.begin(), comb.end()));
	}

	sort(ans.begin(), ans.end());
	cout << ans[0];

	return 0;
}