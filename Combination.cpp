//��Ʈ��ŷ�� �ϱ� ���ؼ� ������ ���տ� ���� �˾ƾ� ����(����, ���� - ��Ʈ��ŷ)
//���� - <algorithm> ����� next_permutation(iter::begin(), iter::end())�� ����Ѵ�.
// next_permutation -> bool�� return(���� ������ ������ true, ������ false)
//nPr ���� - reverse(iter::begin() + r, iter::end()) �� next_permutation���
//nCr ���� - �� �ٸ� �迭���� true�� r���� ���� ex) a = [true,true,false,false] -> 4C2 ����
//�� �迭�� prev_permutation -> ���� ������ ������ true, ������ false ��ȯ�� �̿��� �ش�
//�ε����� �ش��ϴ� ���� �̿�
//������ �������� ����, ������ �������� ������ �Ǿ�� �Ѵ�!

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

		//������ �迭�� �������� ����
		vector<int>comb(chicken.size(), false);
		for (int i = 0; i < t; i++) {
			comb[i] = true;
		}

		do {
			int sum = 0;
			vector<int>dist(house.size(), 100000); //�� ���� ġŲ �Ÿ�

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