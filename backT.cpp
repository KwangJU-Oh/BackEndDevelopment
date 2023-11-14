#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int>>v(20, vector<int>(20));

int m = 1000000000;

void backTracking(vector<bool>comb, int n) { //���� ������ ���� ��Ʈ��ŷ
	do {
		vector<int>teamStart; //�� ��ŸƮ
		vector<int>teamLink;  //�� ��ũ
		vector<bool>startComb(n/2, false); //�� ��ŸƮ �������� �� ������ ���� �迭
		vector<bool>linkComb(n/2, false); //�� ��ũ �������� �� ������ ���� �迭
		int sumStart = 0;
		int sumLink = 0;
		
		for (int i = 0; i < n; i++) { //�� ��ŸƮ�� ��ũ ������
			if (comb[i] == true) {
				teamStart.push_back(i);
			}
			else {
				teamLink.push_back(i);
			}
		}

		for (int j = 0; j < 2; j++) {
			startComb[j] = true;
			linkComb[j] = true;
		}

		do { //�� ��ŸƮ �������� �� ������
			int idx1 = 1000000;
			int idx2 = 1000000;
			for (int a = 0; a < n / 2; a++) {
				if (startComb[a] == true) {
					if (idx1 == 1000000) {
						idx1 = teamStart[a];
					}
					else {
						idx2 = teamStart[a];
					}
				}
			}
			sumStart = sumStart + v[idx1][idx2] + v[idx2][idx1];
		} while (prev_permutation(startComb.begin(), startComb.end()));

		do { //�� ��ũ �������� �� ������
			int idx1 = 1000000;
			int idx2 = 1000000;
			for (int a = 0; a < n / 2; a++) {
				if (linkComb[a] == true) {
					if (idx1 == 1000000) {
						idx1 = teamLink[a];
					}
					else {
						idx2 = teamLink[a];
					}
				}
			}
			sumLink = sumLink + v[idx1][idx2] + v[idx2][idx1];
		} while (prev_permutation(linkComb.begin(), linkComb.end()));

		if (abs(sumLink - sumStart) < m) { //�� �� �ּڰ� ������ ����
			m = abs(sumLink - sumStart);
		}
	} while (prev_permutation(comb.begin(), comb.end()));
}

int main() {
	int n, a;

	cin >> n;
	cin.get();

	vector<bool>comb(n, false);
	for (int i = 0; i < n / 2; i++) {
		comb[i] = true;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			cin.get();
			v[i][j] = a;
		}
	}

	backTracking(comb, n);
	cout << m;

	return 0;
}